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
#define INF (int)2e9
#define LINF (ll)1e18

ll dist(pll a, pll b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	vector<int> A(K);
	vector<pll> pos(N);
	FOR(i, 0, K - 1) {
		cin >> A[i];
		A[i] -= 1;
	}
	FOR(i, 0, N - 1) {
		cin >> pos[i].first >> pos[i].second;
	}

	ll maxi = 0;
	FOR(i, 0, N - 1) {
		ll mini = LINF;
		FOR(j, 0, K - 1) {
			mini = min(mini, dist(pos[i], pos[A[j]]));
		}
		maxi = max(maxi, mini);
	}

	long double ans = sqrtl(maxi);
	cout << fixed << setprecision(6);
	cout << ans;

	return 0;
}