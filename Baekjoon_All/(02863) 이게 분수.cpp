#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	double a, b, c, d;
	double maximum = -1;
	double temp;
	int ans;
	cin >> a >> b;
	cin >> c >> d;
	int idx = 0;
	while (idx < 4) {
		temp = a / c + b / d;
		if (temp > maximum) {
			maximum = temp;
			ans = idx;
		}
		double t;
		t = b;
		b = a;
		a = c;
		c = d;
		d = t;
		idx++;
	}
	cout << ans;

	return 0;
}