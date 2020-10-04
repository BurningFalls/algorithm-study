#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll N;
	ll a, b, c;
	while (true) {
		cin >> N;
		if (N == 0)
			break;
		cin >> a >> b >> c;
		if (b - a == c - b) {
			ll d = b - a;
			cout << N * (2 * a + (N - 1) * d) / 2;
		}
		else {
			ll r = b / a;
			cout << a * (ll(pow(r, N)) - 1) / (r - 1);
		}
		cout << "\n";
	}

	return 0;
}