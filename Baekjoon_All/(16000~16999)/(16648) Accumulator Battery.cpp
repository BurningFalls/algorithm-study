#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	double t, p, temp;
	cin >> t >> p;
	cout << fixed << setprecision(4);
	if (p > 20) {
		temp = t / (100 - p);
		cout << (p - 20) * temp + 40 * temp;
	}
	else if (p <= 20) {
		temp = t / (120 - 2 * p);
		cout << 2 * temp * p;
	}

	return 0;
}