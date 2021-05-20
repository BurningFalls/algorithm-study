#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int main() {
	FASTIO;
	int N, K;
	int dist[101][101];
	cin >> N >> K;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			dist[i][j] = INF;
		}
	}
	FOR(i, 1, K) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	FOR(k, 1, N) {
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (i == j || j == k || i == k) continue;
				if (dist[i][k] == INF || dist[k][j] == INF) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	bool flag = true;
	FOR(i, 1, N) {
		FOR(j, i + 1, N) {
			if (dist[i][j] > 6) {
				flag = false;
				break;
			}
		}
	}
	cout << (flag ? "Small World!" : "Big World!");

	return 0;
}