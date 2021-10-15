#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

ll GCD(ll a, ll b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<ll> v(N);
		ll mini = INF;
		ll gcd = 0;
		FOR(i, 0, N - 1) {
			cin >> v[i];
			mini = min(mini, v[i]);
		}
		FOR(i, 0, N - 1) {
			gcd = GCD(v[i] - mini, gcd);
		}
		if (gcd == 0)
			gcd = -1;
		P1(gcd);
	}


	return 0;
}