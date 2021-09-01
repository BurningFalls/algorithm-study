#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 2100000000

int N, M, K;
int S, D;
vector<pii> edge[1001];
priority_queue<pair<int, pii>> q;
int Dist[1001][1001];

void DT() {
	q.push({ 0, {S, 0} });
	Dist[S][0] = 0;
	while (!q.empty()) {
		int cdist = -q.top().first;
		int node = q.top().second.first;
		int cnt = q.top().second.second;
		q.pop();
		int len = edge[node].size();
		FOR(i, 0, len - 1) {
			int next = edge[node][i].first;
			int ndist = cdist + edge[node][i].second;
			if (Dist[next][cnt + 1] > ndist) {
				Dist[next][cnt + 1] = ndist;
				q.push({ -ndist, {next, cnt + 1} });
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	FOR(i, 1, N) FOR(j, 1, N)
		Dist[i][j] = INF;
	cin >> S >> D;
	FOR(i, 1, M) {
		int a, b, w;
		cin >> a >> b >> w;
		edge[a].push_back({ b, w });
		edge[b].push_back({ a, w });
	}
	DT();
	int sum = 0;
	FOR(k, 0, K) {
		int mini = INF;
		int p;
		if (k != 0) {
			cin >> p;
			sum += p;
		}
		FOR(i, 1, N)
			mini = min(mini, Dist[D][i] + i * sum);
		cout << mini << "\n";
	}


	return 0;
}