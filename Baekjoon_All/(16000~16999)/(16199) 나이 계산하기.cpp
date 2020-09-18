#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int a, b, c;
	int x, y, z;
	int ans1, ans2, ans3;
	cin >> a >> b >> c;
	cin >> x >> y >> z;
	if (a == x) {
		ans1 = 0;
	}
	else {
		int temp = x - a;
		if (b > y) {
			ans1 = temp - 1;
		}
		else if (b == y) {
			if (c <= z) {
				ans1 = temp;
			}
			else if (c > z) {
				ans1 = temp - 1;
			}
		}
		else if (b < y) {
			ans1 = temp;
		}
	}

	ans2 = x - a + 1;

	ans3 = ans2 - 1;

	cout << ans1 << "\n" << ans2 << "\n" << ans3;

	return 0;
}