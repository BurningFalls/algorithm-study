#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
char arr[100001];
int dp[100001][3][2] = { 0, };

int Fight(char a, char b) {
	if ((a == 'H' && b == 'S') ||
		(a == 'S' && b == 'P') ||
		(a == 'P' && b == 'H'))
		return 1;
	else
		return 0;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	int result;
	FOR(i, 1, N) {
		result = Fight('P', arr[i]);
		dp[i][0][0] = max(dp[i][0][0], dp[i - 1][0][0] + result);
		dp[i][0][1] = max({ dp[i][0][1], dp[i - 1][0][1] + result, dp[i-1][1][0] + result, dp[i-1][2][0] + result });
		result = Fight('H', arr[i]);
		dp[i][1][0] = max(dp[i][1][0], dp[i - 1][1][0] + result);
		dp[i][1][1] = max({ dp[i][1][1], dp[i - 1][1][1] + result, dp[i - 1][0][0] + result, dp[i - 1][2][0] + result });
		result = Fight('S', arr[i]);
		dp[i][2][0] = max(dp[i][2][0], dp[i - 1][2][0] + result);
		dp[i][2][1] = max({ dp[i][2][1], dp[i - 1][2][1] + result, dp[i - 1][0][0] + result, dp[i - 1][1][0] + result });
	}
	cout << max({ dp[N][0][0], dp[N][0][1], dp[N][1][0], dp[N][1][1], dp[N][2][0], dp[N][2][1] });

	return 0;
}