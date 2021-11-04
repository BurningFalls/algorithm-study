#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define MOD 1000000000

vvi operator* (const vvi & a, const vvi & b) {
	int len = a.size();
	vvi tmp(len, vi(len));
	FOR(i, 0, len - 1) {
		FOR(j, 0, len - 1) {
			FOR(k, 0, len - 1) {
				tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	return tmp;
}

vvi Power(vvi a, ll b) {
	int len = a.size();
	vvi tmp(len, vi(len));
	FOR(i, 0, len - 1) {
		tmp[i][i] = 1;
	}
	while (b) {
		if (b % 2 == 1) {
			tmp = tmp * a;
		}
		b /= 2;
		a = a * a;
	}
	return tmp;
}

int main() {
	FASTIO;
	ll N, M;
	cin >> N >> M;
	vvi A = { {1, 1}, {1, 0} };
	vvi a = Power(A, N + 1);
	vvi b = Power(A, M + 2);
	ll ans = (b[0][1] % MOD - a[0][1] % MOD + MOD) % MOD;
	cout << ans;

	return 0;
}