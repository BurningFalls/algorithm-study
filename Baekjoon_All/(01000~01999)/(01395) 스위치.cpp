#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int
#define MAX 100000

int N, M;
int tree[4 * MAX + 1] = { 0, };
bool lazy[4 * MAX + 1] = { 0, };

void Update_Lazy(int node, int start, int end) {
	if (lazy[node]) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] ^= 1;
			lazy[node * 2 + 1] ^= 1;
		}
		lazy[node] = 0;
	}
}

int Query(int node, int start, int end, int left, int right) {
	Update_Lazy(node, start, end);
	if (end < left || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	int LQ = Query(node * 2, start, mid, left, right);
	int RQ = Query(node * 2 + 1, mid + 1, end, left, right);
	return LQ + RQ;
}

void Update_Range(int node, int start, int end, int left, int right) {
	Update_Lazy(node, start, end);
	if (end < left || right < start)
		return;
	if (left <= start && end <= right) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] ^= 1;
			lazy[node * 2 + 1] ^= 1;
		}
		return;
	}
	int mid = (start + end) / 2;
	Update_Range(node * 2, start, mid, left, right);
	Update_Range(node * 2 + 1, mid + 1, end, left, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		int O, S, T;
		cin >> O >> S >> T;
		if (O == 0) {
			Update_Range(1, 1, N, S, T);
		}
		else if (O == 1) {
			cout << Query(1, 1, N, S, T) << "\n";
		}
	}

	return 0;
}