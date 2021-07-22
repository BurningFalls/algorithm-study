#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int pizza[1002];
int dp[1002][1002][202];
int ans = 0;

int DP(int start, int cnt, int diff) {
	if (cnt == 0)
		return diff;
	int& ret = dp[start][cnt][diff];
	if (ret != -1)
		return ret;
	if (diff <= 100) {
		ret = max(DP((start + 1) % N, cnt - 1, diff + pizza[start]), 
			DP(start, cnt - 1, diff + pizza[(start + cnt - 1) % N]));
	}
	else if (diff > 100) {
		ret = min(DP((start + 1) % N, cnt - 1, diff - pizza[start]), 
			DP(start, cnt - 1, diff - pizza[(start + cnt - 1) % N]));
	}
	return ret;
}

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	int sum = 0;
	cin >> N;
	FOR(i, 0, N - 1) {
		cin >> pizza[i];
		sum += pizza[i];
	}
	FOR(start, 0, N - 1) {
		ans = max(ans, DP((start + 1) % N, N - 1, 100 + pizza[start]));
	}
	cout << (sum + ans - 100) / 2;

	return 0;
}