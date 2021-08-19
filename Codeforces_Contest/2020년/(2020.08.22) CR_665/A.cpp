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
		int n, k;
		cin >> n >> k;
		if (n <= k)
			cout << k - n;
		else if (n > k) {
			if (n % 2 == 0 && k % 2 == 0)
				cout << 0;
			else if (n % 2 == 1 && k % 2 == 1)
				cout << 0;
			else
				cout << 1;
		}
		cout << "\n";
	}

	return 0;
}