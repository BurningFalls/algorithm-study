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
vector<pii> dp(100001, {-1, 0});

pii DP(int cur) {
	pii& ret = dp[cur];
	if (ret.first >= 0) {
		return ret;
	}
	ret.first = 0;
	int cnt1 = INF, cnt2 = -1;
	FOR(i, cur + 1, min(N, cur + K)) {
		if (dp[i].first == -2) continue;
		pii tmp = DP(i);
		ret.first |= (1 - tmp.first);
		if (tmp.first == 0) {
			cnt1 = min(cnt1, tmp.second + 1);
		}
		else if (tmp.first == 1) {
			cnt2 = max(cnt2, tmp.second + 1);
		}
	}

	if (cnt1 == INF) cnt1 = 0;
	if (cnt2 == -1) cnt2 = 0;
	ret.second = (ret.first == 1 ? cnt1 : cnt2);

	return ret;
}

int main() {
	FASTIO;
	cin >> N >> K;
	int num;
	while (cin >> num) {
		dp[num].first = -2;
	}
	
	pii ans = { 0, 0 };
	int cnt1 = INF, cnt2 = -1;
	FOR(i, 1, min(N, K)) {
		if (dp[i].first == -2) continue;
		pii tmp = DP(i);
		ans.first |= (1 - tmp.first);
		if (tmp.first == 0) {
			cnt1 = min(cnt1, tmp.second + 1);
		}
		else if (tmp.first == 1) {
			cnt2 = max(cnt2, tmp.second + 1);
		}
	}
	if (cnt1 == INF) cnt1 = 0;
	if (cnt2 == -1) cnt2 = 0;
	ans.second = (ans.first == 1 ? cnt1 : cnt2);

	cout << ans.second;

	return 0;
}