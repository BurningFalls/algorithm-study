#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int a, b, c;
	while (cin >> a >> b >> c) {
		int cnt = 0;
		while (!(b - a == 1 && c - b == 1)) {
			if (b - a <= c - b) {
				a = b;
				b = a + 1;
			}
			else if (b - a > c - b) {
				c = b;
				b = c - 1;
			}
			cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}