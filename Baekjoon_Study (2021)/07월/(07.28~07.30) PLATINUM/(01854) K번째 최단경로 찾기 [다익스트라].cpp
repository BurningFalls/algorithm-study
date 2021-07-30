#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 2100000000

int N, M, K;
vector<pii> edge[1001];
priority_queue<int> dist[1001];

void DT() {
	priority_queue<pii> pq;
	dist[1].push(0);
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		int cur_cost = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();
		int len = edge[cur_node].size();
		FOR(i, 0, len - 1) {
			int next_node = edge[cur_node][i].first;
			int next_cost = cur_cost + edge[cur_node][i].second;
			int dist_len = dist[next_node].size();
			if (dist_len < K) {
				dist[next_node].push(next_cost);
				pq.push({ -next_cost, next_node });
			}
			else {
				if (dist[next_node].top() > next_cost) {
					dist[next_node].pop();
					dist[next_node].push(next_cost);
					pq.push({ -next_cost, next_node });
				}
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	FOR(i, 1, M) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
	}
	DT();
	FOR(i, 1, N) {
		int len = dist[i].size();
		if (len < K)
			cout << -1;
		else
			cout << dist[i].top();
		cout << "\n";
	}


	return 0;
}