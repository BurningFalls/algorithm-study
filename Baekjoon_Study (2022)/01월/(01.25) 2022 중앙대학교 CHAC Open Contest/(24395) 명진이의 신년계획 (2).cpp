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
#define INF 2e9
#define LINF 1e18

vector<vector<int>> dp(51, vector<int>(51, -1));

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	dp[0][0] = 0;
	FOR(i, 0, M - 1) {
		int r, b, d;
		cin >> r >> b >> d;
		ROF(i, 50, r) {
			ROF(j, 50, b) {
				if (dp[i - r][j - b] == -1) continue;
				dp[i][j] = max(dp[i][j], dp[i - r][j - b] + d);
			}
		}
	}

	vector<pii> ans;
	FOR(idx, 1, N) {
		int r, b;
		cin >> r >> b;
		ans.push_back({ max(0, dp[r][b]), idx });
	}
	sort(ALL(ans));
	for (pii x : ans) {
		cout << x.second << " " << x.first << "\n";
	}


	return 0;
}