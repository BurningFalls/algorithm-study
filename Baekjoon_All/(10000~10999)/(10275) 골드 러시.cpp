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
		ll n, a, b;
		cin >> n >> a >> b;
		int mini = 63;
		FOR(i, 0, n) {
			if (a & (1LL << i)) {
				mini = i;
				break;
			}
		}
		FOR(i, 0, n) {
			if (b & (1LL << i)) {
				mini = min(mini, i);
				break;
			}
		}
		cout << n - mini << "\n";
	}


	return 0;
}