#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int c1, c2, c3;
	int x, y, z;
	cin >> c1 >> x;
	cin >> c2 >> y;
	cin >> c3 >> z;
	int cnt = 0;
	while (cnt < 100) {
		int tmp;
		if (cnt % 3 == 0) {
			tmp = min(x, c2 - y);
			x -= tmp;
			y += tmp;
		}
		else if (cnt % 3 == 1) {
			tmp = min(y, c3 - z);
			y -= tmp;
			z += tmp;
		}
		else if (cnt % 3 == 2) {
			tmp = min(z, c1 - x);
			z -= tmp;
			x += tmp;
		}
		cnt++;
	}
	cout << x << "\n" << y << "\n" << z;

	return 0;
}