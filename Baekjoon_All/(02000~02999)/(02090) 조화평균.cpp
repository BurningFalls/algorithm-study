#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll GCD(ll a, ll b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int main() {
	FASTIO;
	ll N;
	ll arr[10];
	ll lcm = 1;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
		lcm = lcm * arr[i] / GCD(lcm, arr[i]);
	}
	ll up = lcm, down = 0;
	FOR(i, 1, N) {
		down += lcm / arr[i];
	}
	ll gcd = GCD(up, down);
	up = up / gcd;
	down = down / gcd;
	cout << up << "/" << down;


	return 0;
}