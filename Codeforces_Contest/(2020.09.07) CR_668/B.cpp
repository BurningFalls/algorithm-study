#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

ll arr[100001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n;
		ll ans = 0;
		ll p = 0;
		cin >> n;
		FOR(i, 1, n)
			cin >> arr[i];
		FOR(i, 1, n) {
			if (arr[i] < 0) {
				ll temp = -arr[i];
				if (temp <= p) {
					p -= temp;
				}
				else if (temp > p) {
					ans += (temp - p);
					p = 0;
				}
			}
			else if (arr[i] > 0) {
				p += arr[i];
			}
		}
		cout << ans << "\n";
	}

	return 0;
}