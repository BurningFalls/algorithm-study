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
#define matrix vector<vector<ll>>

matrix Multi(matrix& A, matrix& B, int P) {
	int size = LEN(A);
	matrix tmp(size, vector<ll>(size, 0));
	FOR(i, 0, size - 1) {
		FOR(j, 0, size - 1) {
			FOR(k, 0, size - 1) {
				tmp[i][j] = (tmp[i][j] + A[i][k] * B[k][j]) % P;
			}
		}
	}
	return tmp;
}

matrix Pow(matrix A, int N, int P) {
	int size = LEN(A);
	matrix tmp(size, vector<ll>(size, 0));
	FOR(i, 0, size - 1) {
		tmp[i][i] = 1;
	}
	while (N) {
		if (N % 2 == 1) {
			tmp = Multi(tmp, A, P);
		}
		N /= 2;
		A = Multi(A, A, P);
	}
	return tmp;
}

int main() {
	FASTIO;
	int N, K, P;
	cin >> N >> K;
	vector<ll> v(K);
	FOR(i, 0, K - 1) {
		cin >> v[i];
	}
	cin >> P;
	matrix A(K, vector<ll>(K, 0)), result;
	A[0][0] = 1;
	FOR(i, 1, K - 1) {
		A[0][i] = 1;
		A[i][i - 1] = 1;
	}
	result = Pow(A, N - K, P);

	ll ans = 0;
	FOR(i, 0, K - 1) {
		ans = (ans + v[K - 1 - i] * result[0][i]) % P;
	}
	cout << ans;

	return 0;
}