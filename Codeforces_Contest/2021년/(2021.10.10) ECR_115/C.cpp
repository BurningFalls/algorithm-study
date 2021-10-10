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

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<ll> v(N);
		ll sum = 0;
		FOR(i, 0, N - 1) {
			cin >> v[i];
			sum += v[i];
		}
		sort(ALL(v));
		ll cnt = 0;
		FOR(i, 0, N - 1) {
			ll num = 2 * (sum - v[i]) - v[i] * (N - 2);
			if (num % N != 0) continue;
			num /= N;
			ll lb = lower_bound(v.begin() + i + 1, v.end(), num) - v.begin();
			ll ub = upper_bound(v.begin() + i + 1, v.end(), num) - v.begin();
			cnt += (ub - lb);
		}
		cout << cnt << "\n";
	}

	return 0;
}