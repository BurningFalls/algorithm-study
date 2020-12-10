#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	pii arr[21];
	int dp[101];
	memset(dp, -1, sizeof(dp));
	dp[100] = 0;
	dp[0] = 0;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i].first;
	FOR(i, 1, N)
		cin >> arr[i].second;
	sort(arr + 1, arr + N + 1);
	FOR(i, 1, N) {
		FOR(j, 1, 100) {
			if (j + arr[i].first > 100) continue;
			if (dp[j + arr[i].first] == -1) continue;
			dp[j] = max(dp[j], dp[j + arr[i].first] + arr[i].second);
		}
	}
	int maximum = 0;
	FOR(i, 1, 100)
		maximum = max(maximum, dp[i]);
	cout << maximum;

	return 0;
}