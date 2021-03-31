#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int dp[1001];

int main() {
	FASTIO;
	dp[1] = 1;
	FOR(i, 2, 1000) {
		int tmp = dp[i - 1] * i;
		while (tmp % 10 == 0)
			tmp /= 10;
		tmp %= 10000;
		dp[i] = tmp;
	}
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << dp[N] % 10 << "\n";
	}


	return 0;
}