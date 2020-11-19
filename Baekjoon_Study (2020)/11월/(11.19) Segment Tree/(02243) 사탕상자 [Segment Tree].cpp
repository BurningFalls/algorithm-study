#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 1000000

int N;
ll tree[4 * MAX + 1] = { 0, };

ll Query(int node, int start, int end, int k) {
	if (start == end) {
		return start;
	}
	int mid = (start + end) / 2;
	if (tree[node * 2] >= k)
		return Query(node * 2, start, mid, k);
	else
		return Query(node * 2 + 1, mid + 1, end, k - tree[node * 2]);
}

void Update(int node, int start, int end, int idx, ll diff) {
	if (idx < start || end < idx)
		return;
	tree[node] += diff;
	if (start == end)
		return;
	int mid = (start + end) / 2;
	Update(node * 2, start, mid, idx, diff);
	Update(node * 2 + 1, mid + 1, end, idx, diff);
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		int A, B;
		ll C;
		cin >> A;
		if (A == 1) {
			cin >> B;
			int Idx = Query(1, 1, MAX, B);
			cout << Idx << "\n";
			Update(1, 1, MAX, Idx, -1);
		}
		else if (A == 2) {
			cin >> B >> C;
			Update(1, 1, MAX, B, C);
		}
	}

	return 0;
}