#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

vector<bool> is_prime(1000001, 1);

int main() {
	ll N;
	cin >> N;
	ll ans = 0;
	FOR(i, 2, N) {
		if (!is_prime[i]) continue;
		ans += i;
		for (int j = i * 2; j <= N; j += i) {
			if (is_prime[j] == 1) {
				ans += i;
				is_prime[j] = 0;
			}
		}
	}
	cout << ans;

	return 0;
}