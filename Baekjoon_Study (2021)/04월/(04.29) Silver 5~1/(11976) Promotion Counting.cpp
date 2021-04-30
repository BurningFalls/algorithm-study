#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int A, B, C, D;
	FOR(i, 0, 3) {
		int a, b;
		cin >> a >> b;
		if (i == 0)
			A = b - a;
		else if (i == 1)
			B = b - a;
		else if (i == 2)
			C = b - a;
		else if (i == 3)
			D = b - a;
	}
	cout << B + C + D << "\n" << C + D << "\n" << D;

	return 0;
}