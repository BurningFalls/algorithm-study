#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	cin >> N;
	int Lx, Ly, Rx, Ry;
	bool flag = true;
	FOR(i, 1, N) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (i == 1) {
			Lx = a; Rx = b;
			Ly = c; Ry = d;
		}
		else {
			if (b <= Lx || Rx <= a || d <= Ly || Ry <= c)
				flag = false;
			else {
				Lx = max(Lx, a);
				Rx = min(Rx, b);
				Ly = max(Ly, c);
				Ry = min(Ry, d);
			}
		}
	}
	if (!flag)
		cout << 0;
	else
		cout << (Rx - Lx) * (Ry - Ly);

	return 0;
}