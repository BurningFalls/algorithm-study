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
	ll a, b;
	vector<pii> v;
	cin >> a >> b;
	ll x, y;
	ll gcd, lcm;
	FOR(i, 1, sqrt(a * b)) {
		if ((a * b) % i == 0) {
			x = i;
			y = (a * b) / i;
			gcd = GCD(x, y);
			lcm = x * y / gcd;
			if (gcd == a && lcm == b)
				v.push_back({ x, y });
		}
	}
	int ans1, ans2;
	int minimum = -1;
	FOR(i, 0, v.size() - 1) {
		if (minimum == -1) {
			minimum = v[i].first + v[i].second;
			ans1 = v[i].first;
			ans2 = v[i].second;
		}
		else {
			if (minimum > v[i].first + v[i].second) {
				minimum = v[i].first + v[i].second;
				ans1 = v[i].first;
				ans2 = v[i].second;
			}
		}
	}
	cout << ans1 << " " << ans2;

	return 0;
}