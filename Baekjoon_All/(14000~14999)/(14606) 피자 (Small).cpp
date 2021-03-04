#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	int N;
	int dp[11];
	dp[1] = 0;
	FOR(i, 2, 10) {
		int maximum = 0;
		FOR(j, 1, i / 2) {
			int a = j;
			int b = i - j;
			int tmp = a * b + dp[a] + dp[b];
			maximum = max(maximum, tmp);
		}
		dp[i] = maximum;
	}
	cin >> N;
	cout << dp[N];

	return 0;
}