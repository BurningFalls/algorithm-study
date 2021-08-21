#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 998244353

int arr[5001];
ll dp[5001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	dp[1] = 1;
	FOR(i, 1, N) {
		ll sum = 1;
		FOR(j, 1, i - 1) {
			if (arr[j] < arr[i])
				sum = (sum + dp[j]) % MOD;
		}
		dp[i] = sum;
	}
	FOR(i, 1, N)
		cout << dp[i] << " ";

	return 0;
}