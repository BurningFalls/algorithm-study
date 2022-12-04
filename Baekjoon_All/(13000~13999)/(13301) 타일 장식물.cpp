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

vector<ll> fib(81);

int main() {
	FASTIO;
	int N;
	cin >> N;
	fib[1] = 1;
	fib[2] = 1;
	FOR(i, 3, N) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	ll ans = 4;
	FOR(i, 2, N) {
		ans += 2 * fib[i];
	}
	cout << ans;

	return 0;
}