#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 10007

int C[53][53];

int main() {
	FASTIO;
	FOR(i, 0, 52) {
		C[i][0] = 1;
		C[i][i] = 1;
		FOR(j, 1, i - 1)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 1; i * 4 <= N; i++) {
		ans = (ans + (i % 2 ? 1 : -1) * C[13][i] * C[52 - 4 * i][N - 4 * i]) % MOD;
	}
	if (ans < 0)
		ans += MOD;
	cout << ans;

	return 0;
}