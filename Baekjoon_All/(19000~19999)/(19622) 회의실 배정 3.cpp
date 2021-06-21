#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001];
int dp[100001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int s, e, cnt;
		cin >> s >> e >> cnt;
		arr[i] = cnt;
	}
	dp[0] = 0;
	dp[1] = arr[1];
	FOR(i, 2, N) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
	}
	cout << dp[N];

	return 0;
}