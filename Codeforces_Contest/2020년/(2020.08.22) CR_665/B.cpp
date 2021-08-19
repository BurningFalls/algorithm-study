#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int x1, y1, z1;
		int x2, y2, z2;
		int sum = 0;
		cin >> x1 >> y1 >> z1;
		cin >> x2 >> y2 >> z2;
		if (z1 >= y2) {
			sum += 2 * y2;
			int temp = z1 - y2;
			if (temp + x1 < z2) {
				sum -= 2 * (z2 - temp - x1);
			}
		}
		else if (z1 < y2) {
			sum += 2 * z1;
			if (x1 < z2) {
				sum -= 2 * (z2 - x1);
			}
		}
		cout << sum << "\n";
	}

	return 0;
}