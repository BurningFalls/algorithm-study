#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int dp[100001][1 << 4] = { 0, };
int arr[100001];

int main() {
	FASTIO;
	int num;
	int idx = 1;
	while (true) {
		cin >> num;
		if (num == 0)
			break;
		arr[idx] = num;
		idx++;
	}
	int N = idx - 1;
	FOR(i, 1, N) {
		FOR(j, 0, (1 << 4) - 1) {
			dp[i][j] = 400001;
		}
	}
	dp[1][1 << (arr[1] - 1)] = 2;
	FOR(i, 2, N) {
		int node = arr[i] - 1;
		FOR(j, 1, (1 << 4) - 1) {
			int cnt = 0;
			FOR(k, 0, 3) {
				if (j & (1 << k))
					cnt++;
			}
			if (cnt >= 3)
				continue;
			if (j & (1 << node)) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			}
			else {
				int dif;
				FOR(k, 0, 3) {
					if (j & (1 << k)) {
						dif = abs(k - node);
						if (dif == 1 || dif == 3) {
							int x = (j | (1 << node)) & ~(1 << k);
							dp[i][x] = min(dp[i][x], dp[i - 1][j] + 3);
						}
						else if (dif == 2) {
							int x = (j | (1 << node)) & ~(1 << k);
							dp[i][x] = min(dp[i][x], dp[i - 1][j] + 4);
						}
						if (cnt == 1) {
							int x = (j | (1 << node));
							dp[i][x] = min(dp[i][x], dp[i - 1][j] + 2);
						}
					}
				}
			}
		}
	}
	int minimum = 400001;
	FOR(i, 1, (1 << 4) - 1) {
		minimum = min(minimum, dp[N][i]);
	}
	cout << minimum;

	return 0;
}