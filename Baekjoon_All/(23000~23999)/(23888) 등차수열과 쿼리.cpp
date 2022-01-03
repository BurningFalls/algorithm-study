#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

ll Gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}

int main() {
	FASTIO;
	ll A, D, Q;
	cin >> A >> D;
	cin >> Q;
	FOR(q, 1, Q) {
		ll kind, l, r;
		cin >> kind >> l >> r;
		if (kind == 1) {
			ll tmp1 = r * (2 * A + (r - 1) * D) / 2;
			ll tmp2 = (l - 1) * (2 * A + (l - 2) * D) / 2;
			cout << tmp1 - tmp2 << "\n";
		}
		else if (kind == 2) {
			if (l == r) {
				cout << A + (l - 1) * D << "\n";
			}
			else {
				cout << Gcd(A, D) << "\n";
			}
		}
	}


	return 0;
}