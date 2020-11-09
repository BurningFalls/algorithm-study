#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 2100000000;

int N;
bool imp[101] = { 0, };
int dp[101][101];

int DP(int day, int cp) {
	if (day > N)
		return 0;
	int& ret = dp[day][cp];
	if (ret != -1)
		return ret;
	if (imp[day])
		return ret = DP(day + 1, cp);
	ret = INF;
	ret = min(ret, DP(day + 1, cp) + 10000);
	ret = min(ret, DP(day + 3, cp + 1) + 25000);
	ret = min(ret, DP(day + 5, cp + 2) + 37000);
	if (cp >= 3)
		ret = min(ret, DP(day + 1, cp - 3));
	return ret;
}

int main() {
	FASTIO;
	int M;
	cin >> N >> M;
	FOR(i, 1, M) {
		int num;
		cin >> num;
		imp[num] = 1;
	}
	memset(dp, -1, sizeof(dp));
	cout << DP(1, 0);

	return 0;
}