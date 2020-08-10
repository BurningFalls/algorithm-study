#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int N;
	int dp[31];
	int s[31];
	cin >> N;
	dp[0] = 1;
	dp[1] = 1;
	s[0] = 1;
	s[1] = 1;
	s[2] = 3;
	s[3] = 1;
	for (int i = 2; i <= N; i++)
		dp[i] = dp[i - 2] * 2 + dp[i - 1];
	for (int i = 4; i <= N; i++)
		s[i] = s[i - 4] * 2 + s[i - 2];
	cout << (dp[N] - s[N]) / 2 + s[N];

	return 0;
}