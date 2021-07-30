#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 100001
#define INF 1000000001

int N, M;
vector<int> tree[4 * MAX];

void Init(int node, int start, int end, int idx, int value) {
	if (idx < start || end < idx)
		return;
	tree[node].push_back(value);
	if (start == end)
		return;
	int mid = (start + end) / 2;
	Init(node * 2, start, mid, idx, value);
	Init(node * 2 + 1, mid + 1, end, idx, value);
}

int Get(int node, int start, int end, int left, int right, int value) {
	if (end < left || right < start)
		return 0;
	if (left <= start && end <= right)
		return upper_bound(tree[node].begin(), tree[node].end(), value) - tree[node].begin();
	int mid = (start + end) / 2;
	int LQ = Get(node * 2, start, mid, left, right, value);
	int RQ = Get(node * 2 + 1, mid + 1, end, left, right, value);
	return LQ + RQ;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		Init(1, 1, N, i, num);
	}
	FOR(i, 1, 4 * MAX - 1) {
		if (tree[i].empty())
			break;
		sort(tree[i].begin(), tree[i].end());
	}

	FOR(t, 1, M) {
		int a, b, c;
		cin >> a >> b >> c;
		int left = -INF, right = INF;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (Get(1, 1, N, a, b, mid) < c)
				left = mid + 1;
			else
				right = mid - 1;
		}
		cout << left << "\n";
	}


	return 0;
}