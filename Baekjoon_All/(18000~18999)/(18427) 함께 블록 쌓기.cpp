#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF int(2e9)
#define LINF ll(1e18)
#define MOD 10007

int main() {
	FASTIO;
	int N, M, H;
	cin >> N >> M >> H;
	vector<vector<int>> v(N, vector<int>());
	vector<int> dp(H + 1, 0);

	cin.ignore();
	FOR(i, 0, N - 1) {
		string s;
		getline(cin, s);
		string tmp = "";
		FOR(j, 0, LEN(s) - 1) {
			if (s[j] == ' ') {
				v[i].push_back(stoi(tmp));
				tmp = "";
			}
			else {
				tmp += s[j];
			}
		}
		v[i].push_back(stoi(tmp));
	}

	dp[0] = 1;
	FOR(i, 0, N - 1) {
		ROF(k, H, 0) {
			FOR(j, 0, LEN(v[i]) - 1) {
				if (k - v[i][j] < 0) continue;
				dp[k] = (dp[k] + dp[k - v[i][j]]) % MOD;
			}
		}
	}

	cout << dp[H];

	return 0;
}