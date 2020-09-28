#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		ll n;
		cin >> n;
		ll idx = 1;
		while(true) {
			ll temp = idx * (idx + 1);
			if (n <= temp) {
				if (n <= temp - idx)
					cout << 2 * (idx - 1);
				else
					cout << 2 * (idx - 1) + 1;
				break;
			}
			idx++;
		}
		cout << "\n";
	}

	return 0;
}