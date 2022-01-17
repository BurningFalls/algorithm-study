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

int main() {
	FASTIO;
	ll N, d;
	cin >> N >> d;
	vector<ll> v;
	vector<ll> fact(d);
	fact[0] = 1;
	FOR(i, 1, d - 1) {
		fact[i] = fact[i - 1] * d;
	}
	FOR(i, 0, d - 1) {
		v.push_back(i);
	}
	bool flag = true;
	ll ans = -1;
	while (flag) {
		if (v[0] != 0) {
			ll tmp = 0;
			FOR(i, 0, d - 1) {
				tmp += v[i] * fact[d - 1 - i];
			}
			if (tmp > N) {
				ans = tmp;
				break;
			}
		}
		flag = next_permutation(ALL(v));
	}
	cout << ans;

	return 0;
}