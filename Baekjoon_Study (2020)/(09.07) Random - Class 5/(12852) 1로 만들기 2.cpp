#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int dp[1000001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	dp[1] = 0;
	FOR(i, 2, N) {
		dp[i] = dp[i - 1];
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3]);
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2]);
		dp[i] += 1;
	}
	cout << dp[N] << "\n";
	while (N != 1) {
		cout << N << " ";
		if (N % 3 == 0 && dp[N / 3] == dp[N] - 1)
			N /= 3;
		else if (N % 2 == 0 && dp[N / 2] == dp[N] - 1)
			N /= 2;
		else
			N -= 1;
	}
	cout << 1;

	return 0;
}