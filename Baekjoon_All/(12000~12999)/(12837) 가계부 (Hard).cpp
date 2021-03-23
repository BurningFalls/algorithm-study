#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 1000000

int N, Q;
ll tree[4 * MAX + 1] = { 0, };

ll Find(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	ll LQ = Find(node * 2, start, mid, left, right);
	ll RQ = Find(node * 2 + 1, mid + 1, end, left, right);
	return LQ + RQ;
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
	cin >> N >> Q;
	FOR(i, 1, Q) {
		int kind;
		cin >> kind;
		if (kind == 1) {
			int p;
			ll x;
			cin >> p >> x;
			Update(1, 1, N, p, x);
		}
		else if (kind == 2) {
			int p, q;
			cin >> p >> q;
			cout << Find(1, 1, N, p, q) << "\n";
		}
	}



	return 0;
}