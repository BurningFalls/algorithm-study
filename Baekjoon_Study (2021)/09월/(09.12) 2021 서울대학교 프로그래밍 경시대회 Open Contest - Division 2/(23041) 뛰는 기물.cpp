#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

ll Gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}

int main() {
	FASTIO;
	ll N, M;
	cin >> N >> M;
	if (N < M)
		swap(N, M);
	ll gcd = Gcd(N, M);
	N = N / gcd;
	M = M / gcd;
	gcd = gcd * gcd;
	cout << ((N % 2 && M % 2) ? gcd * 2 : gcd);

	return 0;
}