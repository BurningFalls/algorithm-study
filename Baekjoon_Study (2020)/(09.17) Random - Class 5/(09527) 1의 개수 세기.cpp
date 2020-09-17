#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

ll Calc(ll num) {
	num++;
	ll x = num, ans = 0;
	for (ll t = 1; x != 0; t <<= 1) {
		if (num & t)
			ans += num % t + (num - num % (t * 2)) / 2;
		else
			ans += (num - num % t) / 2;
		x >>= 1;
	}
	return ans;
}

int main() {
	FASTIO;
	ll A, B;
	cin >> A >> B;
	cout << Calc(B) - Calc(A - 1);

	return 0;
}