#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 4001

int N, M;
vector<vector<pii>> Edge(MAX, vector<pii>());
vector<vector<vector<int>>> dist(2, vector<vector<int>>(MAX, vector<int>(2, INF)));

void DT(int idx) {
	PQ<pair<int, pii>> pq;
	pq.push({ 0, {1, 0} });
	dist[idx][1][0] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second.first;
		int cnt = pq.top().second.second;
		pq.pop();
		if (dist[idx][cur][cnt] < cost) continue;
		FOR(i, 0, LEN(Edge[cur]) - 1) {
			int next = Edge[cur][i].first;
			int ncost = Edge[cur][i].second;
			int ncnt = cnt;
			if (idx == 1) {
				ncnt = (ncnt + 1) % 2;
				if (cnt == 0) ncost /= 2;
				else if (cnt == 1) ncost *= 2;
			}
			if (dist[idx][next][ncnt] > cost + ncost) {
				dist[idx][next][ncnt] = cost + ncost;
				pq.push({ -dist[idx][next][ncnt], {next, ncnt} });
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		int a, b, d;
		cin >> a >> b >> d;
		Edge[a].push_back({ b, 2 * d });
		Edge[b].push_back({ a, 2 * d });
	}

	DT(0);
	DT(1);

	int ans = 0;
	FOR(i, 1, N) {
		ans += (dist[0][i][0] < min(dist[1][i][0], dist[1][i][1]));
	}
	cout << ans;

	return 0;
}