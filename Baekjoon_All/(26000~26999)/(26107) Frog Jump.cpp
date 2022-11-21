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

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	vector<pll> v(N + 1);
	vector<ll> route(K + 1);
	vector<ll> jumping(N + 1, 0);
	FOR(i, 1, N) {
		cin >> v[i].first >> v[i].second;
	}
	route[0] = 1;
	FOR(i, 1, K) {
		cin >> route[i];
	}
	ll right = v[1].second;
	FOR(i, 2, N) {
		if (right < v[i].first) {
			jumping[i] = v[i].first - right;
		}
		right = max(right, v[i].second);
	}
	FOR(i, 2, N) {
		jumping[i] += jumping[i - 1];
	}

	ll sum = 0;
	FOR(i, 1, K) {
		sum += abs(jumping[route[i]] - jumping[route[i - 1]]);
	}
	cout << sum;

	return 0;
}