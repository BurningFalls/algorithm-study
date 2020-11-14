#include <bits/stdc++.h>
using namespace std;

#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(); std::cout.tie();
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define INF 3276801

int N, M;
int arr[101];
int sum[101];
int dp[101][51];

int DP(int n, int cnt) {
	if (cnt == 0)
		return 0;
	if (n < 1)
		return -INF;
	int& ret = dp[n][cnt];
	if (ret != -INF)
		return ret;
	ret = -INF;
	ret = max(ret, DP(n - 1, cnt));
	FOR(i, 1, n)
		ret = max(ret, (sum[n] - sum[i - 1]) + DP(i - 2, cnt - 1));
	return ret;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) FOR(j, 1, M)
		dp[i][j] = -INF;
	arr[0] = 0;
	sum[0] = 0;
	FOR(i, 1, N) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	cout << DP(N, M);

	return 0;
}