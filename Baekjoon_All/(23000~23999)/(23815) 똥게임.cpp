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

int Calc(int x, string s) {
	char oper = s[0];
	int num = s[1] - '0';
	if (x == 0) {
		return 0;
	}
	int ans;
	if (oper == '+')
		ans = x + num;
	else if (oper == '-')
		ans = x - num;
	else if (oper == '*')
		ans = x * num;
	else if (oper == '/')
		ans = x / num;
	return max(0, ans);
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<vector<string>> choice(N + 1, vector<string>(2));
	vector<vector<int>> dp(N + 1, vector<int>(2));
	FOR(i, 1, N) {
		FOR(j, 0, 1) {
			cin >> choice[i][j];
		}
	}
	dp[0][0] = 1;
	dp[0][1] = 0;
	FOR(i, 1, N) {
		int a = Calc(dp[i - 1][0], choice[i][0]);
		int b = Calc(dp[i - 1][0], choice[i][1]);
		int c = Calc(dp[i - 1][1], choice[i][0]);
		int d = Calc(dp[i - 1][1], choice[i][1]);
		dp[i][0] = max(a, b);
		dp[i][1] = max({ dp[i - 1][0], c, d });
	}
	int ans = max(dp[N][0], dp[N][1]);
	if (ans == 0) {
		cout << "ddong game";
	}
	else {
		cout << ans;
	}

	return 0;
}