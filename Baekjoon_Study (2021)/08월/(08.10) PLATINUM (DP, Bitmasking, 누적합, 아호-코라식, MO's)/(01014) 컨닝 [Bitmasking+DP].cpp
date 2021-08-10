#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
char Map[11][11];
int dp[11][1025];
bool is_pos[1025] = { 0, };

bool num_Possible(int num) {
	FOR(i, 0, 10) {
		if (i != 0 && (num & (1 << i)) && (num & (1 << (i - 1))))
			return false;
	}
	return true;
}

bool is_Possible(int col, int num) {
	FOR(i, 0, M - 1) {
		if (num & (1 << i)) {
			if (Map[col][i] == 'x')
				return false;
		}
	}

	return true;
}

int Counting(int num) {
	int cnt = 0;
	FOR(i, 0, 10) {
		if (num & (1 << i)) {
			cnt++;
		}
	}
	return cnt;
}

void Make_DP(int col, int num) {
	if (col == 0) {
		dp[col][num] = Counting(num);
		return;
	}
	int maxi = -1;
	FOR(i, 0, (1 << M) - 1) {
		if (dp[col - 1][i] == -1) continue;
		bool flag = true;
		FOR(j, 0, M - 1) {
			if (!(num & (1 << j))) continue;
			if ((j != 0) && (i & (1 << (j - 1)))) {
				flag = false;
				break;
			}
			if (i & (1 << (j + 1))) {
				flag = false;
				break;
			}
		}
		if (flag) {
			maxi = max(maxi, dp[col - 1][i] + Counting(num));
		}
	}
	dp[col][num] = maxi;
}

int main() {
	FASTIO;
	FOR(i, 0, 1024)
		is_pos[i] = num_Possible(i);
	int C;
	cin >> C;
	while (C--) {
		memset(dp, -1, sizeof(dp));
		cin >> N >> M;
		FOR(i, 0, N - 1) {
			FOR(j, 0, M - 1) {
				cin >> Map[i][j];
			}
		}
		FOR(i, 0, N - 1) {
			FOR(j, 0, (1 << M) - 1) {
				if (!is_pos[j]) continue;
				if (!is_Possible(i, j)) continue;
				Make_DP(i, j);
			}
		}
		int maxi = 0;
		FOR(i, 0, (1 << M) - 1) {
			maxi = max(maxi, dp[N - 1][i]);
		}
		cout << maxi << "\n";
	}


	return 0;
}