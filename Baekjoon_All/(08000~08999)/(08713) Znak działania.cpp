#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int a, b;
	cin >> a >> b;
	int x = a + b;
	int y = a - b;
	int z = a * b;
	if (x > y&& x > z) {
		if (a < 0)
			cout << "(" << a << ")";
		else
			cout << a;
		cout << "+";
		if (b < 0)
			cout << "(" << b << ")";
		else
			cout << b;
		cout << "=";
		if (x < 0)
			cout << "(" << x << ")";
		else
			cout << x;
	}
	else if (y > x&& y > z) {
		if (a < 0)
			cout << "(" << a << ")";
		else
			cout << a;
		cout << "-";
		if (b < 0)
			cout << "(" << b << ")";
		else
			cout << b;
		cout << "=";
		if (y < 0)
			cout << "(" << y << ")";
		else
			cout << y;
	}
	else if (z > x&& z > y) {
		if (a < 0)
			cout << "(" << a << ")";
		else
			cout << a;
		cout << "*";
		if (b < 0)
			cout << "(" << b << ")";
		else
			cout << b;
		cout << "=";
		if (z < 0)
			cout << "(" << z << ")";
		else
			cout << z;
	}
	else
		cout << "NIE";

	return 0;
}