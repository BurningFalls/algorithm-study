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
		ll a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;
		ll temp1 = a - x;
		ll temp2 = b - y;
		if (temp1 + temp2 >= n) {
			if (temp1 >= n && temp2 >= n) {
				cout << min((a - n) * b, (b - n) * a);
			}
			else if (temp1 < n && temp2 >= n) {
				ll u = (a - temp1) * (b - (n - temp1));
				ll v = a * (b - n);
				cout << min(u, v);
			}
			else if (temp1 >= n && temp2 < n) {
				ll u = (b - temp2) * (a - (n - temp2));
				ll v = (a - n) * b;
				cout << min(u, v);
			}
			else if (temp1 < n && temp2 < n) {
				ll u = (a - temp1) * (b - (n - temp1));
				ll v = (b - temp2) * (a - (n - temp2));
				cout << min(u, v);
			}
		}
		else if (temp1 + temp2 < n) {
			cout << x * y;
		}
		cout << "\n";
	}

	return 0;
}