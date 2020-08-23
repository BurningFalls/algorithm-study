#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 200
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int rela[101][101];

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (i == j)
				rela[i][j] = 0;
			else
				rela[i][j] = INF;
		}
	}
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		rela[a][b] = 1;
		rela[b][a] = 1;
	}
	FOR(k, 1, N) {
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (i == j || i == k || j == k) continue;
				if (rela[i][k] == INF || rela[k][j] == INF) continue;
				rela[i][j] = min(rela[i][j], rela[i][k] + rela[k][j]);
			}
		}
	}
	int minimum = -1;
	int ans = 0;
	FOR(i, 1, N) {
		int sum = 0;
		FOR(j, 1, N) {
			if (i == j) continue;
			sum += rela[i][j];
		}
		if (minimum == -1) {
			minimum = sum;
			ans = i;
		}
		else {
			if (minimum > sum) {
				minimum = sum;
				ans = i;
			}
		}
	}
	cout << ans;

	return 0;
}