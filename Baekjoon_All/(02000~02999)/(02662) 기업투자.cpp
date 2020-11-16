#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
int arr[21][301] = { 0, };
int dp[21][301];
int ans[21];

int DP(int ep, int invest) {
	if (invest < 0)
		return -1;
	int& ret = dp[ep][invest];
	if (ep < 1 || invest == 0)
		return ret = 0;
	if (ret != -1)
		return ret;
	FOR(i, 0, N) {
		int temp = DP(ep - 1, invest - i);
		if (temp == -1) continue;
		ret = max(ret, temp + arr[ep][i]);
	}
	return ret;
}

void DP_BT(int ep, int invest) {
	FOR(i, 0, N) {
		if (dp[ep - 1][invest - i] + arr[ep][i] == dp[ep][invest]) {
			ans[ep] = i;
			DP_BT(ep - 1, invest - i);
			break;
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		FOR(j, 1, M) {
			cin >> arr[j][i];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << DP(M, N) << "\n";
	DP_BT(M, N);
	FOR(i, 1, M)
		cout << ans[i] << " ";

	return 0;
}