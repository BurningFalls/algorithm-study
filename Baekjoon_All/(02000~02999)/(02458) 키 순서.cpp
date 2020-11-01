#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
int conn[501][501] = { 0, };

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		conn[a][b] = 1;
		conn[b][a] = -1;
	}
	FOR(k, 1, N) {
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (i == k || j == k || i == j) continue;
				if (conn[i][k] == 1 && conn[k][j] == 1)
					conn[i][j] = 1;
				if (conn[i][k] == -1 && conn[k][j] == -1)
					conn[i][j] = -1;
			}
		}
	}
	int ans = 0;
	FOR(i, 1, N) {
		int cnt = 0;
		FOR(j, 1, N) {
			if (conn[i][j] != 0)
				cnt++;
		}
		if (cnt == N - 1)
			ans++;
	}
	cout << ans;

	return 0;
}