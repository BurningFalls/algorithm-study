#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int Gcd(int a, int b) {
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		int x, na, nb, gcd;
		gcd = Gcd(a, b);
		a = a / gcd;
		b = b / gcd;
		while (a != 1) {
			x = ceil((double)b / a);
			na = a * x - b;
			nb = b * x;
			a = na;
			b = nb;
			gcd = Gcd(a, b);
			a = a / gcd;
			b = b / gcd;
		}
		cout << b << "\n";
	}

	return 0;
}