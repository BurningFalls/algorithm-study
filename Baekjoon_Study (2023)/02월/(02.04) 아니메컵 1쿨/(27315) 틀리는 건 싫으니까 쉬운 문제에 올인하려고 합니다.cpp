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
	ll D;
	ll chD;
	ll P;
	ll T;
	ll E;

	bool operator<(const NODE& n) const {
		return chD < n.chD;
	}
};

int main() {
	FASTIO;
	ll N, M, HD, HP;
	cin >> N >> M;
	vector<NODE> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i].D >> v[i].P >> v[i].T >> v[i].E;
		if (v[i].T == 1) {
			v[i].P = 0;
		}
		if (v[i].E == 0) {
			v[i].chD = v[i].D;
		}
		else if (v[i].E == 1) {
			v[i].chD = (v[i].D + 1) / 2;
			v[i].P /= 2;
		}
	}
	cin >> HD >> HP;
	sort(ALL(v));

	ll ans = 0;
	int idx = 0;
	int cnt = 0;
	PQ<ll> pq;
	while (cnt < M) {
		while (idx < N) {
			if (v[idx].E == 0) {
				if (v[idx].D <= HD) {
					pq.push(-v[idx].P);
				}
				else {
					break;
				}
			}
			else if (v[idx].E == 1) {
				if (v[idx].D <= 2 * HD) {
					pq.push(-v[idx].P);
				}
				else {
					break;
				}
			}
			idx++;
		}
		if (pq.empty()) break;
		ll x = -pq.top();
		pq.pop();
		ans += max(0LL, x - HP);
		cnt++;
		HD++, HP++;
	}
	cout << (cnt < M ? -1 : ans);

	return 0;
}