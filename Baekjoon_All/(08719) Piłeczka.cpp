#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int n;
	cin >> n;
	FOR(i, 1, n) {
		double x, w;
		cin >> x >> w;
		if (x >= w)
			cout << 0 << "\n";
		else
			cout << ceil(log10(w / x) / log10(2)) << "\n";
	}

	return 0;
}