#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	int N;
	cin >> N;
	int dp[3][3][3][3];
	int tcnt = 0, gcnt = 0, fcnt = 0, pcnt = 0;
	int ans = 0;
	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0] = 1;
	FOR(i, 1, N) {
		char x;
		cin >> x;
		if (x == 'T')
			tcnt = (tcnt + 1) % 3;
		else if (x == 'G')
			gcnt = (gcnt + 1) % 3;
		else if (x == 'F')
			fcnt = (fcnt + 1) % 3;
		else if (x == 'P')
			pcnt = (pcnt + 1) % 3;
		ans += dp[tcnt][gcnt][fcnt][pcnt];
		dp[tcnt][gcnt][fcnt][pcnt] += 1;
	}
	cout << ans;

	return 0;
}