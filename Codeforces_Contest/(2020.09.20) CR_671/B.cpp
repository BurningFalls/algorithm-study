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
	ll arr[31];
	arr[1] = 1;
	FOR(i, 2, 30) {
		arr[i] = arr[i - 1] * 2;
	}
	FOR(i, 2, 30) {
		arr[i] = arr[i - 1] + arr[i];
	}
	FOR(i, 1, 30) {
		arr[i] = arr[i] * (arr[i] + 1) / 2;
	}
	FOR(i, 2, 30) {
		arr[i] = arr[i - 1] + arr[i];
	}
	while (T--) {
		ll x;
		int ans = 31;
		cin >> x;
		FOR(i, 1, 30) {
			if (x < arr[i]) {
				ans = i;
				break;
			}
		}
		cout << ans - 1 << "\n";
	}

	return 0;
}