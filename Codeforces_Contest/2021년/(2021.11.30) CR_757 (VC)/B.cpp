#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

bool compare(pll a, pll b) {
	return a.first > b.first;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<pll> v(N);
		vector<pll> v2(N);
		vector<ll> ans(N + 1);
		FOR(i, 0, N - 1) {
			ll num;
			cin >> num;
			v[i] = { num, i + 1 };
		}
		v2 = v;
		sort(ALL(v), compare);
		ans[0] = 0;
		for (int i = 0; i <= N - 1; i += 2) {
			v[i].first = i / 2 + 1;
		}
		for (int i = 1; i <= N - 1; i += 2) {
			v[i].first = -(i / 2 + 1);
		}
		ll sum = 0;
		FOR(i, 0, N - 1) {
			ans[v[i].second] = v[i].first;
		}
		FOR(i, 0, N - 1) {
			sum += abs(ans[i + 1]) * v2[i].first;
		}
		cout << sum * 2 << "\n";
		for (ll x : ans) {
			cout << x << " ";
		}
		cout << "\n";
	}

	return 0;
}