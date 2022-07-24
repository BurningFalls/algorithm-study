#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

bool compare1(pll a, pll b) {
	return a.second > b.second;
}

bool compare2(pll a, pll b) {
	return a.first > b.first;
}

int main() {
	FASTIO;
	int N, M, K;
	cin >> N >> M >> K;
	vector<pll> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i].first >> v[i].second;
	}
	sort(ALL(v), compare1);
	ll ans = 0;
	FOR(i, 0, K - 1) {
		ans += v[i].first;
	}
	sort(v.begin() + K, v.end(), compare2);
	FOR(i, K, K + M - 1) {
		ans += v[i].first;
	}
	cout << ans;

	return 0;
}