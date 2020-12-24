#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

vector<pair<int, pii>> V[101];
int timing[101][10001];

int DT(int goal, int limit_cost) {
	// {시간, {위치, 비용}}
	priority_queue<pair<int, pii>> pq;
	timing[1][0] = 0;
	pq.push({ 0, {1, 0} });
	while (!pq.empty()) {
		int cur_time = -pq.top().first;
		int cur_pos = pq.top().second.first;
		int cur_cost = pq.top().second.second;
		pq.pop();
		if (timing[cur_pos][cur_cost] < cur_time) continue;
		if (cur_cost > limit_cost) continue;
		if (cur_pos == goal)
			return cur_time;
		int len = V[cur_pos].size();
		FOR(i, 0, len - 1) {
			int next_pos = V[cur_pos][i].first;
			int next_cost = V[cur_pos][i].second.first + cur_cost;
			int next_time = V[cur_pos][i].second.second + cur_time;
			if (next_cost > limit_cost) continue;
			if (next_time < timing[next_pos][next_cost]) {

				FOR(j, next_cost + 1, limit_cost) {
					if (timing[next_pos][j] <= next_time) break;
					timing[next_pos][j] = next_time;
				}

				timing[next_pos][next_cost] = next_time;
				pq.push({ -next_time, {next_pos, next_cost} });
			}
		}
	}
	return -1;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, M, K;
		int u, v, c, d;
		cin >> N >> M >> K;
		if (N == 1) {
			cout << "0\n";
			continue;
		}
		if (K == 0) {
			cout << "Poor KCM\n";
			continue;
		}
		FOR(i, 1, N)
			V[i].clear();
		FOR(i, 1, N) {
			FOR(j, 0, M) {
				timing[i][j] = INF;
			}
		}
		FOR(i, 1, K) {
			cin >> u >> v >> c >> d;
			// {위치, {비용, 시간}}
			V[u].push_back({ v, {c, d} });
		}
		int flag = DT(N, M);
		if (flag == -1)
			cout << "Poor KCM";
		else
			cout << flag;
		cout << "\n";
	}

	return 0;
}