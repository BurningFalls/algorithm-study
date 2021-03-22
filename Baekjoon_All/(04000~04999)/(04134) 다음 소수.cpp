#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define ROF(i,a,b) for(ll i=(a);i>=(b);i--)
#define pii pair<int, int>

bool Is_Prime(ll x) {
	FOR(i, 2, sqrt(x)) {
		if (x % i == 0)
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	int T;
	ll N;
	cin >> T;
	while (T--) {
		cin >> N;
		if (N <= 2) {
			cout << 2 << "\n";
			continue;
		}
		if (N % 2 == 0)
			N += 1;
		while (true) {
			if (Is_Prime(N)) {
				cout << N << "\n";
				break;
			}
			N += 2;
		}
	}

	return 0;
}