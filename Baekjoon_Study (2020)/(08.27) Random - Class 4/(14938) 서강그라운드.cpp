#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 987654321
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N, M, R;
int T[101];
int dist[101][101];

int main() {
	int ans = 0;
	cin >> N >> M >> R;
	FOR(i, 1, N)
		cin >> T[i];
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
	}
	FOR(i, 1, R) {
		int a, b, l;
		cin >> a >> b >> l;
		dist[a][b] = l;
		dist[b][a] = l;
	}
	FOR(k, 1, N) {
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (i == j || i == k || k == j) continue;
				if (dist[i][k] == INF || dist[k][j] == INF) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	FOR(i, 1, N) {
		int sum = 0;
		FOR(j, 1, N) {
			if (dist[i][j] > M) continue;
			sum += T[j];
		}
		ans = max(ans, sum);
	}
	cout << ans;

	return 0;
}