#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 987654321
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int n;
deque<char> s;
int dp[200001][5];

int Cal(int idx, int t) {
	int cnt = 0;
	if (t == 1) {
		if (idx + 2 > n)
			return INF;
		if (s[idx] == 'R')
			cnt++;
		if (s[idx + 1] == 'L')
			cnt++;
		return 2 - cnt;
	}
	else if (t == 2) {
		if (idx + 3 > n)
			return INF;
		if (s[idx] == 'R')
			cnt++;
		if (s[idx + 1] == 'R')
			cnt++;
		if (s[idx + 2] == 'L')
			cnt++;
		return 3 - cnt;
	}
	else if (t == 3) {
		if (idx + 3 > n)
			return INF;
		if (s[idx] == 'R')
			cnt++;
		if (s[idx + 1] == 'L')
			cnt++;
		if (s[idx + 2] == 'L')
			cnt++;
		return 3 - cnt;
	}
	else if (t == 4) {
		if (idx + 4 > n)
			return INF;
		if (s[idx] == 'R')
			cnt++;
		if (s[idx + 1] == 'R')
			cnt++;
		if (s[idx + 2] == 'L')
			cnt++;
		if (s[idx + 3] == 'L')
			cnt++;
		return 4 - cnt;
	}
}

int main() {
	FASTIO;
	int T;
	int ans;
	char C;
	cin >> T;
	while (T--) {
		ans = INF;
		s.clear();
		cin >> n;
		FOR(i, 0, n - 1) {
			cin >> C;
			s.push_back(C);
		}
		FOR(k, 0, 3) {
			FOR(i, 0, n - 1) {
				int temp;
				if (i == 0 || i == 1)
					temp = 0;
				else if (i == 2)
					temp = dp[i - 2][1];
				else if (i == 3)
					temp = min({ dp[i - 2][1], dp[i - 3][2], dp[i - 3][3] });
				else
					temp = min({ dp[i - 2][1], dp[i - 3][2], dp[i - 3][3], dp[i - 4][4] });
				FOR(j, 1, 4) {
					int x = Cal(i, j);
					if (x == INF || i == 1)
						dp[i][j] = INF;
					else {
						dp[i][j] = temp + x;
					}
				}
			}
			int dp_min;
			if (n == 3)
				dp_min = min({ dp[n - 3][3], dp[n - 3][2], dp[n - 2][1] });
			else
				dp_min = min({ dp[n - 4][4], dp[n - 3][3], dp[n - 3][2], dp[n - 2][1] });
			ans = min(ans, dp_min);
			if (k != 3) {
				s.push_back(s.front());
				s.pop_front();
			}
		}
		cout << ans << "\n";
	}

	return 0;
}