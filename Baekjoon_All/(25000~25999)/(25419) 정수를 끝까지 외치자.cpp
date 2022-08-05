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

int N, K;
vector<int> dp(100001, -1);

int DP(int cur) {
	int& ret = dp[cur];
	if (ret >= 0) {
		return ret;
	}
	ret = 0;
	FOR(i, cur + 1, min(N, cur + K)) {
		if (dp[i] == -2) continue;
		ret |= (1 - DP(i));
	}
	return ret;
}

int main() {
	FASTIO;
	cin >> N >> K;
	int num;
	while (cin >> num) {
		dp[num] = -2;
	}
	int ans = 0;
	FOR(i, 1, min(N, K)) {
		if (dp[i] == -2) continue;
		ans |= (1 - DP(i));
	}
	cout << ans;

	return 0;
}