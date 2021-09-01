#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000007
typedef ll(*arrPointer)[21];

ll BasicM[21][21] = { 0, };

arrPointer Matrix_Multi(int N, ll A[][21], ll B[][21]) {
	ll R[21][21] = { 0, };
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			FOR(k, 1, N) {
				R[i][j] = (R[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
			}
		}
	}
	return R;
}

arrPointer Matrix_Exp(int N, ll X[][21], int cnt) {
	if (cnt == 0)
		return BasicM;
	ll(*tmp)[21] = Matrix_Exp(N, X, cnt / 2);
	ll(*ans)[21] = Matrix_Multi(N, tmp, tmp);
	if (cnt % 2 == 1)
		ans = Matrix_Multi(N, ans, X);
	return ans;
}

int main() {
	FASTIO;
	ll Matrix[21][21];
	FOR(i, 1, 20)
		BasicM[i][i] = 1;
	int T, N, D;
	cin >> T >> N >> D;
	if (D != 0)
		D = (D - 1) % T + 1;
	ll(*ans)[21] = BasicM;
	FOR(t, 1, T) {
		memset(Matrix, 0, sizeof(Matrix));
		int M;
		cin >> M;
		FOR(m, 1, M) {
			int a, b, c;
			cin >> a >> b >> c;
			Matrix[a][b] = c;
		}
		if (t == D)
			ans = Matrix_Exp(N, Matrix, D);
	}
	int A;
	while (true) {
		cin >> A;
		ans = Matrix_Exp(N, Matrix, A);
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	

	return 0;
}