#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000007

struct M {
	ll arr[2][2];
};

M b;

M multiply(M a, M b) {
	M c;
	c.arr[0][0] = (a.arr[0][0] * b.arr[0][0] + a.arr[0][1] * b.arr[1][0]) % MOD;
	c.arr[0][1] = (a.arr[0][0] * b.arr[0][1] + a.arr[0][1] * b.arr[1][1]) % MOD;
	c.arr[1][0] = (a.arr[1][0] * b.arr[0][0] + a.arr[1][1] * b.arr[1][0]) % MOD;
	c.arr[1][1] = (a.arr[1][0] * b.arr[0][1] + a.arr[1][1] * b.arr[1][1]) % MOD;
	return c;
}

M divide(M a, ll x) {
	if (x > 1) {
		a = divide(a, x / 2);
		a = multiply(a, a);
		if (x % 2 == 1) {
			a = multiply(a, b);
		}
	}
	return a;
}

ll fibo(ll x) {
	M a;
	a.arr[0][0] = 1;
	a.arr[0][1] = 1;
	a.arr[1][0] = 1;
	a.arr[1][1] = 0;
	a = divide(a, x);
	return a.arr[0][1];
}

int main() {
	FASTIO;
	ll n;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	b.arr[0][0] = 1;
	b.arr[0][1] = 1;
	b.arr[1][0] = 1;
	b.arr[1][1] = 0;
	cout << fibo(n);

	return 0;
}