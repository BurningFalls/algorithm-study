#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

ll func(ll a, ll b, ll c) {
	if (b == 0)
		return 1;
	ll temp = func(a, b / 2, c);
	ll result = temp * temp % c;
	if (b % 2 == 1)
		result = result * a % c;
	return result;
}

int main() {
	ll A, B, C;
	cin >> A >> B >> C;
	cout << func(A, B, C);

	return 0;
}