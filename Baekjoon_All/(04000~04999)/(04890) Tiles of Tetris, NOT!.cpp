#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll Gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}

int main() {
	FASTIO; 
	ll W, H;
	while (true) {
		cin >> W >> H;
		if (W == 0 && H == 0)
			break;
		ll gcd = Gcd(W, H);
		cout << (W / gcd) * (H / gcd) << "\n";
	}


	return 0;
}