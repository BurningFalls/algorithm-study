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

int dp[17][1 << 17] = { 0, };
vector<vector<int>> Edge(17, vector<int>());
int max_sheep = 0;

void TWO(int x) {
	vector<int> v;
	while (x) {
		v.push_back(x % 2);
		x /= 2;
	}
	ROF(i, LEN(v) - 1, 0) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

void DFS(int node, int vis, int sheep, vector<int>& info) {
	max_sheep = max(max_sheep, sheep);
	FOR(i, 0, LEN(Edge[node]) - 1) {
		int next = Edge[node][i];
		int nscore = dp[node][vis];
		int nsheep = sheep;
		if (!(vis & (1 << next))) {
			if (info[next] == 0) {
				nscore += 1;
				nsheep += 1;
			}
			else if (info[next] == 1) {
				nscore -= 1;
			}
		}
		int nvis = vis | (1 << next);
		if (dp[next][vis] >= nscore) continue;
		dp[next][nvis] = nscore;
		DFS(next, nvis, nsheep, info);
	}
}

int solution(vector<int> info, vector<vector<int>> edges) {
	int answer = 0;
	FOR(i, 0, LEN(edges) - 1) {
		int a = edges[i][0];
		int b = edges[i][1];
		Edge[a].push_back(b);
		Edge[b].push_back(a);
	}
	dp[0][1] = 1;
	DFS(0, 1, 1, info);
	answer = max_sheep;
	return answer;
}