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
	ll A, B, C, K;
	cin >> A >> B >> C >> K;
	vector<ll> nums = { A * 4, B * 4, C * 2, A + B, A * 2 + C, B * 2 + C };
	vector<ll> cnt = { 4, 4, 2, 2, 3, 3 };
	vector<ll> dp(K + 1, INF);
	dp[0] = 0;
	FOR(i, 0, LEN(nums) - 1) {
		FOR(j, nums[i], K) {
			if (dp[j - nums[i]] == -1) continue;
			dp[j] = min(dp[j], dp[j - nums[i]] + cnt[i]);
		}
	}
	cout << (dp[K] == INF ? -1 : dp[K]);

	return 0;
}