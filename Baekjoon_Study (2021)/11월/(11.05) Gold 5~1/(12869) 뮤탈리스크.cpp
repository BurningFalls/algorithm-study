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

int N;
vector<int> health(3, 0);
int dp[61][61][61];

int DP(int h1, int h2, int h3) {
	if (h1 < 0) h1 = 0;
	if (h2 < 0) h2 = 0;
	if (h3 < 0) h3 = 0;
	if (h1 == 0 && h2 == 0 && h3 == 0) {
		return 0;
	}
	int& ret = dp[h1][h2][h3];
	if (ret != -1) {
		return ret;
	}
	ret = INF;
	int tmp[3] = { 1, 3, 9 };
	bool flag = true;
	while (flag) {
		ret = min(ret, DP(h1 - tmp[0], h2 - tmp[1], h3 - tmp[2]) + 1);
		flag = next_permutation(tmp, tmp + 3);
	}
	return ret;
}

int main() {
	FASTIO;
	FOR(i, 0, 60) {
		FOR(j, 0, 60) {
			FOR(k, 0, 60) {
				dp[i][j][k] = -1;
			}
		}
	}
	cin >> N;
	FOR(i, 0, N - 1) {
		cin >> health[i];
	}
	cout << DP(health[0], health[1], health[2]);

	return 0;
}