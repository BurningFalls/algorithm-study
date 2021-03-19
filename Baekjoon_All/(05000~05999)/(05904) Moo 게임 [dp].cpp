#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int dp[1001];

char Tracking(int n, int pos) {
	if (n == 0) {
		if (pos == 1)
			return 'm';
		else
			return 'o';
	}
	if (pos <= dp[n - 1])
		return Tracking(n - 1, pos);
	else if (dp[n - 1] < pos && pos <= dp[n - 1] + n + 3) {
		if (pos == dp[n - 1] + 1)
			return 'm';
		else
			return 'o';
	}
	else
		return Tracking(n - 1, pos - dp[n - 1] - n - 3);
}

int main() {
	FASTIO;
	dp[0] = 3;
	int idx = 0;
	cin >> N;
	while (true) {
		idx++;
		dp[idx] = dp[idx - 1] * 2 + idx + 3;
		if (dp[idx] >= N)
			break;
	}
	cout << Tracking(idx, N);


	return 0;
}