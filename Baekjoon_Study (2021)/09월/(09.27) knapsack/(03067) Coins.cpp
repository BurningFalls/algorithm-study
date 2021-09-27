#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int coin[21];
int dp[10001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		MEMSET(dp, 0);
		int N, M;
		cin >> N;
		FOR(i, 1, N)
			cin >> coin[i];
		cin >> M;
		dp[0] = 1;
		FOR(i, 1, N) {
			FOR(j, coin[i], M) {
				dp[j] += dp[j - coin[i]];
			}
		}
		cout << dp[M] << "\n";
	}



	return 0;
}