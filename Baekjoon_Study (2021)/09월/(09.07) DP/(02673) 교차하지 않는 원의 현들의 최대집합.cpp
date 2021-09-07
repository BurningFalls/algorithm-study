#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

bool node[101][101] = { 0, };
int dp[101][101];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		node[a][b] = 1;
		node[b][a] = 1;
	}

	FOR(i, 1, 100) {
		ROF(j, i, 1) {
			FOR(k, j, i - 1) {
				dp[j][i] = max(dp[j][i], dp[j][k] + dp[k][i] + node[i][j]);
			}
		}
	}
	cout << dp[1][100];


	return 0;
}