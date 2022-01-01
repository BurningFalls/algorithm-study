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
#define INF 2100000000
#define LINF 1e18

struct NODE {
	ll s;
	ll l;
	ll o;
};

bool compare(NODE a, NODE b) {
	if (a.o == b.o) {
		if (a.l == b.l) {
			return a.s < b.s;
		}
		return a.l > b.l;
	}
	return a.o < b.o;
}

int main() {
	FASTIO;
	int N, G, K;
	cin >> N >> G >> K;
	vector<NODE> v(N);
	int pos_cnt = 0;
	ll left = 0, right = INF;
	FOR(i, 0, N - 1) {
		cin >> v[i].s >> v[i].l >> v[i].o;
		if (v[i].o == 1) {
			pos_cnt++;
		}
	}
	ll ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;
		vector<ll> sums;
		FOR(i, 0, LEN(v) - 1) {
			ll tmp = v[i].s * max(1LL, mid - v[i].l);
			sum += tmp;
			if (v[i].o == 1) {
				sums.push_back(tmp);
			}
		}
		sort(ALL(sums), greater<ll>());
		FOR(i, 0, min(K, LEN(sums)) - 1) {
			sum -= sums[i];
		}
		if (sum <= G) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans;

	return 0;
}