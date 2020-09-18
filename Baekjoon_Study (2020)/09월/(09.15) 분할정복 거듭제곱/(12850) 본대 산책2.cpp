#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MOD 1000000007

ll con[8][8] = { {0, 1, 1, 0, 0, 0, 0, 0},
						  {1, 0, 1, 1, 0, 0, 0, 0},
						  {1, 1, 0, 1, 1, 0, 0, 0},
						  {0, 1, 1, 0, 1, 1, 0, 0},
						  {0, 0, 1, 1, 0, 1, 1, 0},
						  {0, 0, 0, 1, 1, 0, 0, 1},
						  {0, 0, 0, 0, 1, 0, 0, 1},
						  {0, 0, 0, 0, 0, 1, 1, 0} };
ll ans[8][8];

void multing(ll arr1[8][8], ll arr2[8][8]) {
	ll temp[8][8] = { 0, };
	FOR(i, 0, 7) {
		FOR(j, 0, 7) {
			FOR(k, 0, 7) {
				temp[i][j] = (temp[i][j] + arr1[i][k] * arr2[k][j]) % MOD;
			}
		}
	}
	FOR(i, 0, 7)
		FOR(j, 0, 7)
			ans[i][j] = temp[i][j];
}

void powing(int N) {
	if (N == 1)
		return;

	if (N % 2 == 1) {
		powing(N / 2);
		multing(ans, ans);
		multing(ans, con);
	}
	else if (N % 2 == 0) {
		powing(N / 2);
		multing(ans, ans);
	}
}

int main() {
	FASTIO;
	int D;
	cin >> D;

	FOR(i, 0, 7)
		FOR(j, 0, 7)
			ans[i][j] = con[i][j];

	powing(D);
	cout << ans[0][0];

	return 0;
}