#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool use[2001][2001] = { 0, };

int main() {
	FASTIO;
	int a, b, c, d;
	int e, f, g, h;
	int x, y, z, w;
	cin >> a >> b >> c >> d;
	a += 1000;
	b += 1000;
	c += 1000;
	d += 1000;
	FOR(i, a, c - 1) {
		FOR(j, b, d - 1) {
			use[i][j] = 1;
		}
	}
	cin >> e >> f >> g >> h;
	e += 1000;
	f += 1000;
	g += 1000;
	h += 1000;
	FOR(i, e, g - 1) {
		FOR(j, f, h - 1) {
			use[i][j] = 1;
		}
	}
	cin >> x >> y >> z >> w;
	x += 1000;
	y += 1000;
	z += 1000;
	w += 1000;
	FOR(i, x, z - 1) {
		FOR(j, y, w - 1) {
			use[i][j] = 0;
		}
	}
	int cnt = 0;
	FOR(i, a, c - 1) {
		FOR(j, b, d - 1) {
			if (use[i][j])
				cnt++;
		}
	}
	FOR(i, e, g - 1) {
		FOR(j, f, h - 1) {
			if (use[i][j])
				cnt++;
		}
	}
	cout << cnt;

	return 0;
}