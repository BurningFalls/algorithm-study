#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[5001];
int dp[5001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	int max_dp = 2;
	dp[1] = 1;
	dp[2] = 2;
	FOR(i, 3, N) {
		if ((arr[i - 2] <= arr[i - 1] && arr[i - 1] <= arr[i]) ||
			(arr[i - 2] >= arr[i - 1] && arr[i - 1] >= arr[i])) {
			dp[i] = 2;
		}
		else
			dp[i] = dp[i - 1] + 1;
		max_dp = max(max_dp, dp[i]);
	}
	cout << max_dp;


	return 0;
}