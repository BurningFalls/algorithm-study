#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 2100000000

int N, M;
int dist[201][201];
int max_len[201][201];

void Floyd() {
	FOR(k, 1, N) {
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (i == k || k == j || i == j) continue;
				if (dist[i][k] == INF || dist[k][j] == INF) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main() {
	FASTIO;
	cout << fixed << setprecision(1);
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
			max_len[i][j] = -1;
		}
	}
	FOR(i, 1, M) {
		int S, E, L;
		cin >> S >> E >> L;
		dist[S][E] = min(dist[S][E], L);
		dist[E][S] = min(dist[E][S], L);
		max_len[S][E] = max(max_len[S][E], L);
		max_len[E][S] = max(max_len[E][S], L);
	}
	Floyd();
	double ans = INF;
	FOR(start, 1, N) {
		double maxi = 0;
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (max_len[i][j] == -1) continue;
				double rem = max_len[i][j] - (dist[start][j] - dist[start][i]);
				if (rem <= 0) continue;
				double tmp = (rem / 2) + dist[start][j];
				maxi = max(maxi, tmp);
			}
		}
		ans = min(ans, maxi);
	}
	cout << ans;

	return 0;
}