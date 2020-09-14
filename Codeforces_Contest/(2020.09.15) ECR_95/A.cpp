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
		ll x, y, k;
		cin >> x >> y >> k;
		if (((y + 1) * k - 1) % (x - 1) == 0)
			cout << k + ((y + 1) * k - 1) / (x - 1);
		else
			cout << k + ((y + 1) * k - 1) / (x - 1) + 1;
		cout << "\n";
	}

	return 0;
}