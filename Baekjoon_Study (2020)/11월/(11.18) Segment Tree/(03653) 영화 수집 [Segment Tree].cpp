#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 200000

int N, M;
vector<ll> collection, tree;

ll Init(int node, int start, int end) {
	if (start == end) {
		if (start >= M) {
			collection[start - M] = start;
			tree[node] = 1;
		}
		return tree[node];
	}
	int mid = (start + end) / 2;
	ll LQ = Init(node * 2, start, mid);
	ll RQ = Init(node * 2 + 1, mid + 1, end);
	return tree[node] = LQ + RQ;
}

ll Query(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	ll LQ = Query(node * 2, start, mid, left, right);
	ll RQ = Query(node * 2 + 1, mid + 1, end, left, right);
	return LQ + RQ;
}

void Update(int node, int start, int end, int idx, int diff) {
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
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		collection.clear();
		tree.clear();
		collection.resize(N);
		tree.resize(4 * (N + M), 0);
		Init(1, 0, N + M - 1);
		int idx = M - 1;
		FOR(i, 1, M) {
			int num;
			cin >> num;
			cout << Query(1, 0, N + M - 1, 0, collection[num - 1] - 1) << " ";
			Update(1, 0, N + M - 1, collection[num - 1], -1);
			collection[num - 1] = idx;
			Update(1, 0, N + M - 1, collection[num - 1], 1);
			idx--;
		}
		cout << "\n";
	}

	return 0;
}