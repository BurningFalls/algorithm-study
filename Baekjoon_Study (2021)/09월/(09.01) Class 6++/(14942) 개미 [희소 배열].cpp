#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 100001

int N;
int Energy[MAX];
vector<pii> Edge[MAX];
int Dist[MAX];
int Parent[MAX][33];

void BFS() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		int len = Edge[node].size();
		FOR(i, 0, len - 1) {
			int next = Edge[node][i].first;
			int dist = Edge[node][i].second;
			if (Dist[next] != -1) continue;
			Dist[next] = Dist[node] + dist;
			Parent[next][0] = node;
			q.push(next);
		}
	}
}

int main() {
	FASTIO;
	memset(Dist, -1, sizeof(Dist));
	cin >> N;
	FOR(i, 1, N)
		cin >> Energy[i];
	FOR(i, 1, N - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		Edge[a].push_back({ b, c });
		Edge[b].push_back({ a, c });
	}
	Dist[1] = 0;
	Parent[1][0] = 1;
	BFS();
	FOR(j, 1, 31) {
		FOR(i, 1, N) {
			Parent[i][j] = Parent[Parent[i][j - 1]][j - 1];
		}
	}
	FOR(i, 1, N) {
		int node = i;
		int E = Energy[node];
		ROF(j, 31, 0) {
			if (Dist[node] - Dist[Parent[node][j]] <= E) {
				E -= Dist[node] - Dist[Parent[node][j]];
				node = Parent[node][j];
			}
		}
		cout << node << "\n";
	}


	return 0;
}