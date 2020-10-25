#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int dp[101][101][101] = { 0, };

int main() {
	FASTIO;
	int ans = 0;
	string a, b, c;
	cin >> a >> b >> c;
	string x, y, z;
	x = '0' + a;
	y = '0' + b;
	z = '0' + c;
	int xlen = x.size();
	int ylen = y.size();
	int zlen = z.size();
	FOR(i, 1, xlen - 1) {
		FOR(j, 1, ylen - 1) {
			FOR(k, 1, zlen - 1) {
				if (x[i] == y[j] && y[j] == z[k])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else
					dp[i][j][k] = max({ dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1] });
				ans = max(ans, dp[i][j][k]);
			}
		}
	}
	cout << ans;

	return 0;
}