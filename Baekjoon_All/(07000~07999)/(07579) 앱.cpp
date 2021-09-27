#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int memory[101];
int cost[101];
int dp[100001];

int main() {
	FASTIO;
	MEMSET(dp, -1);
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N)
		cin >> memory[i];
	int cost_sum = 0;
	FOR(i, 1, N) {
		cin >> cost[i];
		cost_sum += cost[i];
	}
	dp[0] = 0;
	FOR(i, 1, N) {
		ROF(j, cost_sum, cost[i]) {
			if (dp[j - cost[i]] == -1) continue;
			dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
		}
	}
	int ans = -1;
	FOR(i, 0, cost_sum) {
		if (dp[i] >= M) {
			ans = i;
			break;
		}
	}
	cout << ans;


	return 0;
}