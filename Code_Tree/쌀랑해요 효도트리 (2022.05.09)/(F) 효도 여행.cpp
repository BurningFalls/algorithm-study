#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define MAX 5001

struct NODE {
	int node;
	char kind;
};

int N, M;
string S;
vector<vector<NODE>> Edge(MAX, vector<NODE>());
vector<vector<int>> dp(2, vector<int>(MAX, 0));
int ans = 0;

void DFS(int node, int prev) {
	bool flag = false;
	vector<int> tmp = dp[0];
	FOR(i, 0, LEN(Edge[node]) - 1) {
		int next = Edge[node][i].node;
		char kind = Edge[node][i].kind;
		if (next == prev) continue;
		flag = true;
		FOR(j, 0, M - 1) {
			if (kind == S[j]) {
				dp[1][j + 1] = dp[0][j] + 1;
			}
			else {
				dp[1][j + 1] = max(dp[0][j + 1], dp[1][j]);
			}
		}
		FOR(j, 0, M) {
			dp[0][j] = dp[1][j];
		}
		DFS(next, node);
		dp[0] = tmp;
	}
	if (!flag) {
		ans = max(ans, dp[0][M]);
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	cin >> S;
	FOR(i, 1, N - 1) {
		int u, v;
		char c;
		cin >> u >> v >> c;
		Edge[u].push_back({ v, c });
		Edge[v].push_back({ u, c });
	}

	DFS(1, 0);

	cout << ans;

	return 0;
}