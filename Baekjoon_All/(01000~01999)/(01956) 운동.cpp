#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int V, E;
int conn[401][401];

int main() {
	FASTIO;
	cin >> V >> E;
	FOR(i, 1, V)
		FOR(j, 1, V)
			conn[i][j] = INF;
	FOR(i, 1, E) {
		int a, b, c;
		cin >> a >> b >> c;
		conn[a][b] = c;
	}
	FOR(k, 1, V) {
		FOR(i, 1, V) {
			FOR(j, 1, V) {
				if (i == j || i == k || k == j) continue;
				if (conn[i][k] == INF || conn[k][j] == INF) continue;
				conn[i][j] = min(conn[i][j], conn[i][k] + conn[k][j]);
			}
		}
	}
	int minimum = INF;
	FOR(i, 1, V) {
		FOR(j, i + 1, V) {
			if (conn[i][j] == INF || conn[j][i] == INF) continue;
			minimum = min(minimum, conn[i][j] + conn[j][i]);
		}
	}
	if (minimum == INF)
		cout << -1;
	else
		cout << minimum;

	return 0;
}