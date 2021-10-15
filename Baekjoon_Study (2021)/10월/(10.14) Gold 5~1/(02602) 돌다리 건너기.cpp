#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int main() {
	FASTIO;
	string dur, s[2];
	cin >> dur >> s[0] >> s[1];
	int len = LEN(s[0]);
	int dur_len = LEN(dur);
	vector<vector<vector<int>>> dp(2, vector<vector<int>>(len, vector<int>(dur_len, 0)));
	int ans = 0;
	FOR(i, 0, len - 1) {
		FOR(line, 0, 1) {
			FOR(j, 0, dur_len - 1) {
				if (s[line][i] != dur[j]) continue;
				if (j == 0) {
					dp[line][i][0] = 1;
				}
				else {
					int cnt = 0;
					FOR(k, 0, i - 1) {
						if (s[1 - line][k] == dur[j - 1]) {
							cnt += dp[1 - line][k][j - 1];
						}
					}
					dp[line][i][j] = cnt;
				}
				if (j == LEN(dur) - 1) {
					ans += dp[line][i][j];
				}
			}
		}
	}
	cout << ans;


	return 0;
}