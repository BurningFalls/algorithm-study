#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int A, B, C;
int dp[27][101][101][101];

int DP(int turn, int a, int b, int c) {
	if (a + b + c == 0) {
		return 0;
	}
	int& ret = dp[turn][a][b][c];
	if (ret != -1) {
		return ret;
	}
	ret = -INF;
	if (a > 0) {
		ret = max(ret, min(turn, a) - DP(turn + 1, max(0, a - turn), b, c));
	}
	if (b > 0) {
		ret = max(ret, min(turn, b) - DP(turn + 1, a, max(0, b - turn), c));
	}
	if (c > 0) {
		ret = max(ret, min(turn, c) - DP(turn + 1, a, b, max(0, c - turn)));
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> A >> B >> C;
	int result = DP(1, A, B, C);
	if (result > 0) {
		cout << 'F';
	}
	else if (result == 0) {
		cout << 'D';
	}
	else if (result < 0) {
		cout << 'S';
	}

	return 0;
}