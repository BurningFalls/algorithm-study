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

vector<vector<int>> dp(361, vector<int>(2, -1));
int timing;

int DP(int cur, int state) {
	if (cur > timing) {
		return INF;
	}
	if (cur == timing) {
		return 1 - state;
	}
	int& ret = dp[cur][state];
	if (ret != -1) {
		return ret;
	}
	ret = INF;
	ret = min(ret, DP(cur + 1, state) + 1);
	ret = min(ret, DP(cur + 6, state) + 1);
	ret = min(ret, DP(cur + 60, state) + 1);
	if (state == 0) {
		if (cur == 0) {
			ret = min(ret, DP(cur + 3, 1) + 1);
		}
		else {
			ret = min(ret, DP(cur, 1) + 1);
		}
	}
	else if (state == 1) {
		ret = min(ret, DP(cur + 3, 1) + 1);
	}
	return ret;
}

int main() {
	FASTIO;
	string s;
	cin >> s;
	int min = (s[0] - '0') * 10 + (s[1] - '0');
	int sec = (s[3] - '0') * 10 + (s[4] - '0');
	timing = 60 * min + sec;
	timing /= 10;

	cout << DP(0, 0);

	return 0;
}