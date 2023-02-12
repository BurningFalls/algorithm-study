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

struct NODE {
	ll X;
	ll T;
	ll S;

	bool operator<(const NODE& n) const {
		return X < n.X;
	}
};

int main() {
	FASTIO;
	ll N, K;
	cin >> N >> K;
	vector<NODE> v(K);
	FOR(i, 0, K - 1) {
		cin >> v[i].X >> v[i].T >> v[i].S;
	}
	sort(ALL(v));

	ll time = 0;
	FOR(i, 0, K - 1) {
		if (i == 0) {
			time += v[i].X;
		}
		else {
			time += v[i].X - v[i - 1].X;
		}
		time = max({ time, v[i].S });
		ll tmp = (time - v[i].S) % (2 * v[i].T);
		if (v[i].T <= tmp && tmp < 2 * v[i].T) {
			time += (2 * v[i].T - tmp);
		}
	}
	time += N - (K == 0 ? 0 : v[K - 1].X);

	cout << time;

	return 0;
}