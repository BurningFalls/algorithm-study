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
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

vector<int> TS(int N, int M, vector<int>& indegree, vector<vector<pii>>& edge) {
	queue<int> q;
	vector<vector<int>> part_cnt(N + 1, vector<int>(N + 1, 0));
	FOR(i, 1, N) {
		if (indegree[i] == 0) {
			q.push(i);
			part_cnt[i][i] = 1;
		}
	}
	int final_node = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		final_node = node;
		FOR(i, 0, LEN(edge[node]) - 1) {
			int next = edge[node][i].first;
			int cnt = edge[node][i].second;
			FOR(j, 1, N) {
				part_cnt[next][j] += part_cnt[node][j] * cnt;
			}
			if (--indegree[next] == 0) {
				q.push(next);
			}
		}
	}
	return part_cnt[final_node];
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<int> indegree(N + 1, 0);
	vector<vector<pii>> edge(N + 1);
	vector<int> ans(N + 1);
	FOR(i, 1, M) {
		int X, Y, K;
		cin >> X >> Y >> K;
		indegree[X]++;
		edge[Y].push_back({ X, K });
	}
	ans = TS(N, M, indegree, edge);
	FOR(i, 1, N) {
		if (ans[i] == 0) continue;
		P2(i, ans[i]);
	}

	return 0;
}