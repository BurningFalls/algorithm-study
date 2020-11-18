#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
int loc[100001];
int tree[200005];

void Update(int idx, int val) {
	while (idx < 200005) {
		tree[idx] += val;
		idx += (idx & (-idx));
	}
}

int Query(int idx) {
	int ret = 0;
	while (idx > 0) {
		ret += tree[idx];
		idx -= (idx & (-idx));
	}
	return ret;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		memset(tree, 0, sizeof(tree));
		memset(loc, 0, sizeof(loc));
		cin >> N >> M;
		FOR(i, 1, N) {
			loc[i] = i + M;
			Update(i + M, 1);
		}
		FOR(i, 0, M - 1) {
			int num;
			cin >> num;
			cout << Query(loc[num]) - 1 << " ";
			Update(loc[num], -1);
			loc[num] = M - i;
			Update(loc[num], 1);
		}
		cout << "\n";
	}

	return 0;
}