#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int start, endd;
vector<int> v[1001];
int dist[1001];

void DT() {
	priority_queue<pii> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();
		for (int next : v[cur_node]) {
			if (dist[next] > dist[cur_node] + 1) {
				dist[next] = dist[cur_node] + 1;
				pq.push({ -dist[next], next });
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> start >> endd;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N)
		dist[i] = INF;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	DT();
	cout << (dist[endd] == INF ? -1 : dist[endd]);

	return 0;
}