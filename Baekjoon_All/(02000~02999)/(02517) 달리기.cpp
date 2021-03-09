#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int
#define MAX 500000

int N;
int tree[4 * MAX + 1];
vector<pii> v;

bool cmp(pii a, pii b) {
	return a.second < b.second;
}

int Find(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	int LQ = Find(node * 2, start, mid, left, right);
	int RQ = Find(node * 2 + 1, mid + 1, end, left, right);
	return LQ + RQ;
}

void Update(int node, int start, int end, int idx) {
	if (idx < start || end < idx)
		return;
	tree[node]++;
	if (start == end)
		return;
	int mid = (start + end) / 2;
	Update(node * 2, start, mid, idx);
	Update(node * 2 + 1, mid + 1, end, idx);
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, N - 1) {
		int tmp;
		cin >> tmp;
		v.push_back({ tmp, i });
	}
	sort(v.begin(), v.end());
	FOR(i, 0, N - 1) {
		v[i].first = i;
	}
	sort(v.begin(), v.end(), cmp);
	FOR(i, 0, N - 1) {
		int ans = i - Find(1, 0, MAX, 0, v[i].first) + 1;
		cout << ans << "\n";
		Update(1, 0, MAX, v[i].first);
	}

	return 0;
}