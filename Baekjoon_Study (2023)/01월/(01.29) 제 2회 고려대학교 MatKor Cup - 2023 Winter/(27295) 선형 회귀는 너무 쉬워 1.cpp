#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

ll Gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	return Gcd(b, a % b);
}

int main() {
	FASTIO;
	ll N, b;
	cin >> N >> b;
	ll xsum = 0, ysum = 0;
	FOR(i, 0, N - 1) {
		ll x, y;
		cin >> x >> y;
		xsum += x;
		ysum += y;
	}
	ll up = ysum - b * N;
	ll down = xsum;
	if (down == 0) {
		cout << "EZPZ";
	}
	else {
		int cnt = (up < 0) + (down < 0);
		up = abs(up);
		down = abs(down);
		ll gcd = Gcd(up, down);
		up /= gcd;
		down /= gcd;
		if (cnt == 0 || cnt == 2) {
			cout << up;
			if (down != 1) {
				cout << "/" << down;
			}
		}
		else if (cnt == 1) {
			cout << -up;
			if (down != 1) {
				cout << "/" << down;
			}
		}
	}

	return 0;
}