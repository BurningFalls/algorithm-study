#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	FOR(x, -999, 999) {
		FOR(y, -999, 999) {
			if (a * x + b * y == c &&
				d * x + e * y == f) {
				cout << x << " " << y;
				break;
			}
		}
	}


	return 0;
}