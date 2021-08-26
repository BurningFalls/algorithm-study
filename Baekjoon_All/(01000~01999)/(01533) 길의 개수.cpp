#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000003

int N, S, E, T;
char arr[51][51];
ll A[51][51];
ll ans[51][51];
ll tmp[51][51];

void matrix_multi(ll a[][51], ll b[][51]) {
	memset(tmp, 0, sizeof(tmp));
	FOR(i, 1, 5 * N) {
		FOR(j, 1, 5 * N) {
			FOR(k, 1, 5 * N) {
				tmp[i][j] += (a[i][k] * b[k][j]);
				tmp[i][j] %= MOD;
			}
		}
	}
	FOR(i, 1, 5 * N) {
		FOR(j, 1, 5 * N) {
			a[i][j] = tmp[i][j];
		}
	}
}

void matrix_pow() {
	while (T) {
		if (T % 2)
			matrix_multi(ans, A);
		matrix_multi(A, A);
		T /= 2;
	}
}

int main() {
	FASTIO;
	cin >> N >> S >> E >> T;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> arr[i][j];
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (arr[i][j] - '0' >= 1)
				A[i * 5][j * 5 - (arr[i][j] - '0' - 1)] = 1;
		}
		FOR(j, 1, 4) {
			int idx = (i - 1) * 5 + j;
			A[idx][idx + 1] = 1;
		}
	}
	FOR(i, 1, 5 * N)
		ans[i][i] = 1;
	matrix_pow();
	cout << ans[5 * S][5 * E];

	return 0;
}