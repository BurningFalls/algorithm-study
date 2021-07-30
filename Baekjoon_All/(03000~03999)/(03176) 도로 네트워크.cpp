#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 100001
#define INF 987654321

int N;
vector<pii> edge[MAX];
int depth[MAX];
int Parent[MAX][20];
int maxDP[MAX][20];
int minDP[MAX][20];
int max_level;

void Find_Parent(int cur, int prev, int val) {
	depth[cur] = depth[prev] + 1;
	Parent[cur][0] = prev;
	minDP[cur][0] = val;
	maxDP[cur][0] = val;
	FOR(i, 1, max_level) {
		int tmp = Parent[cur][i - 1];
		Parent[cur][i] = Parent[tmp][i - 1];
	}
	int len = edge[cur].size();
	FOR(i, 0, len - 1) {
		pii next = edge[cur][i];
		if (next.first == prev) continue;
		Find_Parent(next.first, cur, next.second);
	}
}

void Make_DP() {
	FOR(i, 1, max_level) {
		FOR(cur, 1, N) {
			int tmp = Parent[cur][i - 1];
			minDP[cur][i] = min(minDP[cur][i - 1], minDP[tmp][i - 1]);
			maxDP[cur][i] = max(maxDP[cur][i - 1], maxDP[tmp][i - 1]);
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N - 1) {
		int A, B, C;
		cin >> A >> B >> C;
		edge[A].push_back({ B, C });
		edge[B].push_back({ A, C });
	}

	max_level = (int)floor(log2(MAX));
	depth[0] = -1;
	Find_Parent(1, 0, 0);
	Make_DP();

	int K;
	cin >> K;
	FOR(i, 1, K) {
		int D, E;
		int mini = INF;
		int maxi = -1;
		cin >> D >> E;
		if (depth[D] != depth[E]) {
			if (depth[D] > depth[E])
				swap(D, E);
			ROF(i, max_level, 0) {
				if (depth[D] <= depth[Parent[E][i]]) {
					mini = min(mini, minDP[E][i]);
					maxi = max(maxi, maxDP[E][i]);
					E = Parent[E][i];
				}
			}
		}
		int lca = D;
		if (D != E) {
			ROF(i, max_level, 0) {
				if (Parent[D][i] != Parent[E][i]) {
					mini = min({ mini, minDP[D][i], minDP[E][i] });
					maxi = max({ maxi, maxDP[D][i], maxDP[E][i] });
					D = Parent[D][i];
					E = Parent[E][i];
				}
				lca = Parent[D][i];
			}
		}
		if (D != lca) {
			mini = min({ mini, minDP[D][0], minDP[E][0] });
			maxi = max({ maxi, maxDP[D][0], maxDP[E][0] });
		}
		cout << mini << " " << maxi << "\n";
	}


	return 0;
}