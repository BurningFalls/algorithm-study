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

ll Gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	return Gcd(b, a % b);
}

bool compare(pll a, pll b) {
	return a.second * b.first > a.first* b.second;
}

pll Sum(pll a, pll b) {
	ll up = a.first * b.second + a.second * b.first;
	ll down = a.first * b.first;
	ll gcd = Gcd(up, down);
	return { down / gcd, up / gcd };
}

int main() {
	FASTIO;
	int N;
	ll M;
	cin >> N >> M;
	vector<pll> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i].first >> v[i].second;
	}
	sort(ALL(v), compare);

	int idx = 0;
	pll ans = { 1, 0 };
	while (idx < N) {
		if (M <= v[idx].first) {
			ans = Sum(ans, { v[idx].first, v[idx].second * M });
			break;
		}
		ans = Sum(ans, { 1, v[idx].second });
		M -= v[idx].first;
		idx++;
	}
	cout << ans.second << "/" << ans.first;

	return 0;
}