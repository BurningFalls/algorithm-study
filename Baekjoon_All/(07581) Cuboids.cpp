#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int a, b, c, d;
	while (true) {
		cin >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0)
			break;
		if (a == 0)
			a = d / b / c;
		else if (b == 0)
			b = d / c / a;
		else if (c == 0)
			c = d / b / a;
		else if (d == 0)
			d = a * b * c;
		cout << a << " " << b << " " << c << " " << d << "\n";
	}

	return 0;
}