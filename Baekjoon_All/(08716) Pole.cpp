#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	pair<ll, ll> a, b, c, d, temp;
	bool flag = true;
	ll ans = 1;
	ll x[4];
	cin >> a.first >> a.second >> b.first >> b.second;
	cin >> c.first >> c.second >> d.first >> d.second;
	if (a.first > b.first) {
		temp = a;
		a = b;
		b = temp;
	}
	if (c.first > d.first) {
		temp = c;
		c = d;
		d = temp;
	}
	if (b.first <= c.first || d.first <= a.first)
		flag = false;
	else {
		x[0] = a.first;
		x[1] = b.first;
		x[2] = c.first;
		x[3] = d.first;
		sort(x, x + 4);
		ans *= x[2] - x[1];
	}
		

	if (a.second > b.second) {
		temp = a;
		a = b;
		b = temp;
	}
	if (c.second > d.second) {
		temp = c;
		c = d;
		d = temp;
	}
	if (b.second <= c.second || d.second <= a.second)
		flag = false;
	else {
		x[0] = a.second;
		x[1] = b.second;
		x[2] = c.second;
		x[3] = d.second;
		sort(x, x + 4);
		ans *= x[2] - x[1];
	}
	if (!flag)
		cout << 0;
	else
		cout << ans;

	return 0;
}