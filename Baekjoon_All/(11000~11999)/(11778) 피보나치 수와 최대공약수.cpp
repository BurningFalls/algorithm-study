#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MOD 1000000007
#define Matrix vector<vector<ll>>

ll Gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}

Matrix matMultiply(Matrix a, Matrix b) {
	int len1 = LEN(a);
	int len2 = LEN(a[0]);
	int len3 = LEN(b[0]);
	Matrix ans = Matrix(len1, vector<ll>(len3, 0));
	FOR(i, 0, len1 - 1) {
		FOR(j, 0, len3 - 1) {
			FOR(k, 0, len2 - 1) {
				ans[i][j] = (ans[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
			}
		}
	}
	return ans;
}

Matrix matPower(Matrix m, ll n) {
	if (n == 0) {
		return { {1, 0}, {0, 1} };
	}
	if (n == 1) {
		return m;
	}
	Matrix ans = matPower(m, n / 2);
	ans = matMultiply(ans, ans);
	if (n % 2 == 1) {
		ans = matMultiply(ans, m);
	}
	return ans;
}

int main() {
	FASTIO;
	ll N, M;
	cin >> N >> M;
	if (N == 0 || M == 0) {
		cout << 0;
		return 0;
	}
	ll gcd = Gcd(N, M);
	Matrix m = { {1, 1}, {1, 0} };
	cout << matPower(m, gcd - 1)[0][0];

	return 0;
}