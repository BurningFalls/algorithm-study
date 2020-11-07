#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int N, M;
int dp[21][21][21];
int arr[21];

int DP(int cnt, int a, int b) {
	if (cnt == M + 1)
		return 0;
	if (dp[cnt][a][b] != -1)
		return dp[cnt][a][b];
	int temp1 = DP(cnt + 1, arr[cnt], b) + abs(arr[cnt] - a);
	int temp2 = DP(cnt + 1, a, arr[cnt]) + abs(arr[cnt] - b);
	return dp[cnt][a][b] = min(temp1, temp2);
}

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	int x, y;
	cin >> N;
	cin >> x >> y;
	cin >> M;
	FOR(i, 1, M)
		cin >> arr[i];

	cout << DP(1, x, y);

	return 0;
}