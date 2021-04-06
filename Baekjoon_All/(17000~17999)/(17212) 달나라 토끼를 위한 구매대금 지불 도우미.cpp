#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int dp[100001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 0, N)
		dp[i] = i;
	int arr[4] = { 1, 2, 5, 7 };
	FOR(i, 1, 3) {
		FOR(j, arr[i], N) {
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}
	cout << dp[N];

	return 0;
}