#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	ll n, k, s;
	cin >> n;
	k = 4;
	s = 3;
	while (n > s) {
		s = s * 2 + k;
		k += 1;
	}
	k -= 1;
	while (true) {
		ll t = (s - k) / 2;
		if (n <= t) {
			k--;
			s = t;
		}
		else if (n > t + k) {
			n -= (t + k);
			k--;
			s = t;
		}
		else {
			n -= t;
			break;
		}
	}
	if (n == 1) {
		cout << 'm';
	}
	else {
		cout << 'o';
	}


	return 0;
}