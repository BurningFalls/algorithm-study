#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001];
int dp[100001][2];

int main() {
	FASTIO;
	int n;
	int maximum;
	cin >> n;
	FOR(i, 1, n)
		cin >> arr[i];
	dp[1][0] = arr[1];
	dp[1][1] = 0;
	maximum = arr[1];
	FOR(i, 2, n) {
		dp[i][0] = max({ arr[i], dp[i - 1][0] + arr[i] });
		dp[i][1] = max({ dp[i - 1][0], dp[i - 1][1] + arr[i] });
		maximum = max({ maximum, dp[i][0], dp[i][1] });
	}
	cout << maximum;

	return 0;
}