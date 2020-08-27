#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

ll N, B;
ll A[6][6], ans[6][6] = { 0, };

void Multi(ll a[6][6], ll b[6][6]) {
	ll C[6][6] = { 0, };
	FOR(i, 1, N)
		FOR(j, 1, N)
			FOR(k, 1, N)
				C[i][j] = (C[i][j] + a[i][k] * b[k][j]) % 1000;
	FOR(i, 1, N)
		FOR(j, 1, N)
		a[i][j] = C[i][j];
}

int main() {
	FASTIO;
	cin >> N >> B;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> A[i][j];
		}
		ans[i][i] = 1;
	}
	while (B > 0) {
		if (B % 2 == 1)
			Multi(ans, A);
		Multi(A, A);
		B /= 2;
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}