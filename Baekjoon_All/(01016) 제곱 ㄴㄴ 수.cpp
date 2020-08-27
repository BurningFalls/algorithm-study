#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

ll num[1000001];

int main() {
	ll minimum, maximum;
	int cnt = 0;
	cin >> minimum >> maximum;

	for (ll i = 2; i * i <= maximum; i++) {
		ll temp = minimum / (i * i);
		if (minimum % (i * i) != 0)
			temp++;
		while (temp * (i * i) <= maximum) {
			num[temp * (i * i) - minimum] = 1;
			temp++;
		}
	}
	for(ll i = 0; i <= maximum - minimum; i++) {
		if (num[i] == 0)
			cnt++;
	}
	cout << cnt;

	return 0;
}