#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define MOD 1000000007
#define ll long long int

ll dp1[1000001];
ll dp2[1000001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	dp1[0] = 1, dp1[1] = 2;
	dp2[0] = 0, dp2[1] = 1;
	FOR(i, 2, N) {
		dp2[i] = (dp1[i - 1] + dp1[i - 2] + dp2[i - 2]) % MOD;
		dp1[i] = (2 * dp2[i] + dp1[i - 2]) % MOD;
	}
	cout << dp1[N];

	return 0;
}