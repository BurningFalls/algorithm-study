#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	ll M, K;
	cin >> M >> K;
	vector<ll> nums;
	FOR(i, 1, M) {
		ll sum = 0;
		int n = i;
		while (n) {
			sum += n % 10;
			n /= 10;
		}
		if (i % sum == 0) {
			nums.push_back(i);
		}
	}
	vector<ll> dp(M + 1, 0);
	dp[0] = 1;
	FOR(i, 0, LEN(nums) - 1) {
		FOR(j, nums[i], M) {
			dp[j] = (dp[j] + dp[j - nums[i]]) % K;
		}
	}
	cout << dp[M];

	return 0;
}