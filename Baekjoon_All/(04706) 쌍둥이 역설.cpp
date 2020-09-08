#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	double ta, tb;
	cout << fixed << setprecision(3);
	while (true) {
		cin >> ta >> tb;
		if (ta == 0 && tb == 0)
			break;
		double c = 299792458;
		cout << sqrt(c * c - c * c * tb * tb / (ta * ta)) / c << "\n";
	}

	return 0;
}