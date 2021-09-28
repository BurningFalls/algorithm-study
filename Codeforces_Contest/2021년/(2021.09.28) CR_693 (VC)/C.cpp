#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

ll arr[200001];
ll dp[200001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		MEMSET(dp, 0);
		int N;
		cin >> N;
		FOR(i, 1, N) {
			cin >> arr[i];
		}
		FOR(i, 1, N) {
			dp[i] += arr[i];
			if (i + arr[i] <= N)
				dp[i + arr[i]] = max(dp[i + arr[i]], dp[i]);
		}
		ll maxi = 0;
		FOR(i, 1, N)
			maxi = max(maxi, dp[i]);
		cout << maxi << "\n";
	}

	return 0;
}