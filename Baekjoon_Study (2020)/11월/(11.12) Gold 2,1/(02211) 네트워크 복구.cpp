#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int N;
vector<pii> v[1001];
int dist[1001];
int Parent[1001];

void DT() {
	priority_queue<pii> pq;
	dist[1] = 0;
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cost > dist[cur])
			continue;
		int len = v[cur].size();
		FOR(i, 0, len - 1) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;
			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				Parent[next] = cur;
				pq.push({ -dist[next], next });
			}
		}
	}
}

int main() {
	FASTIO;
	int M;
	cin >> N >> M;
	FOR(i, 1, N)
		dist[i] = INF;
	FOR(i, 1, M) {
		int A, B, C;
		cin >> A >> B >> C;
		v[A].push_back({ B, C });
		v[B].push_back({ A, C });
	}
	DT();
	cout << N - 1 << "\n";
	FOR(i, 2, N)
		cout << i << " " << Parent[i] << "\n";

	return 0;
}