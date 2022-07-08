#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

ll Gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}

ll Lcm(ll a, ll b) {
	return (a / Gcd(a, b)) * b;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		if (N == 3) {
			cout << 6 << "\n";
			continue;
		}
		ll a = Lcm(Lcm(N - 3, N - 2), N - 1);
		ll b = Lcm(Lcm(N - 3, N - 2), N);
		ll c = Lcm(Lcm(N - 3, N - 1), N);
		ll d = Lcm(Lcm(N - 2, N - 1), N);
		cout << max({ a, b, c, d }) << "\n";
	}

	return 0;
}