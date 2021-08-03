#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	FASTIO;
	ll a, b;
	cin >> a >> b;
	ll down = b - a;
	ll up = floor(sqrtl(b)) - floor(sqrtl(a));
	ll g = gcd(down, up);
	if (up == 0)
		cout << 0;
	else
		cout << up / g << "/" << down / g;


	return 0;
}