#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int a, b, c;
	if (A > 2 * C)
		a = 2 * C;
	else
		a = A;
	if (B > 2 * C)
		b = 2 * C;
	else
		b = B;
	if (A + B > 2 * C) {
		if (X > Y)
			cout << 2 * C * Y + a * (X - Y);
		else
			cout << 2 * C * X + b * (Y - X);
	}
	else
		cout << a * X + b * Y;

	return 0;
}