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
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";
#define MOD 1000000007

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		ll N, K;
		cin >> N >> K;
		ll ans = 0;
		ll tmp = 1;
		while (K != 0) {
			ans = (ans + tmp * (K % 2)) % MOD;
			K /= 2;
			tmp = (tmp * N) % MOD;
		}
		P1(ans);
	}


	return 0;
}