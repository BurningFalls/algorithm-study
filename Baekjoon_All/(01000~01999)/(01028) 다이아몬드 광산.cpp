#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int R, C;
	cin >> R >> C;
	vector<vector<char>> Map(R + 2, vector<char>(C + 2));
	vector<vector<int>> dp1(R + 2, vector<int>(C + 2, 0));
	vector<vector<int>> dp2(R + 2, vector<int>(C + 2, 0));
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cin >> Map[i][j];
		}
	}

	FOR(i, 1, R) {
		FOR(j, 1, C) {
			if (Map[i][j] == '0') continue;
			dp1[i][j] = dp1[i - 1][j - 1] + 1;
		}
	}
	FOR(i, 1, R) {
		ROF(j, C, 1) {
			if (Map[i][j] == '0') continue;
			dp2[i][j] = dp2[i - 1][j + 1] + 1;
		}
	}

	int max_size = min((R + 1) / 2, (C + 1) / 2);
	int ans = 0;
	ROF(k, max_size, 1) {
		FOR(i, k, R + 1 - k) {
			FOR(j, k, C + 1 - k) {
				int a = dp2[i][j - k + 1];
				int b = dp1[i][j + k - 1];
				int c = dp1[i + k - 1][j];
				int d = dp2[i + k - 1][j];
				if (min({ a, b, c, d }) >= k) {
					ans = max(ans, k);
				}
			}
		}
	}
	cout << ans;

	return 0;
}