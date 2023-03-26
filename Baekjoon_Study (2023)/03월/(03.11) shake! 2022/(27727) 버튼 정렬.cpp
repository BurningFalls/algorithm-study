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
	ll N; 
	ll K;
	cin >> N;
	vector<ll> A(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	cin >> K;

	ll sum = 0;
	ll maxi = 0;
	FOR(i, 0, N - 2) {
		if (A[i] > A[i + 1]) {
			maxi = max(maxi, A[i]);
		}
	}
	FOR(i, 0, N - 1) {
		sum += max(0LL, maxi - A[i]);
		A[i] = max(maxi, A[i]);
	}

	if (sum > K) {
		cout << 0;
	}
	else {
		vector<pll> v;
		ll prev = A[0];
		ll cnt = 1;
		FOR(i, 1, N - 1) {
			if (prev != A[i]) {
				v.push_back({ prev, cnt });
				prev = A[i];
				cnt = 1;
			}
			else if (prev == A[i]) {
				cnt++;
			}
		}
		v.push_back({ prev, cnt });

		ll ans = 0;
		ll maxi = 0, t = 0;
		if (sum != 0) {
			ans++;
		}
		K -= sum;
		FOR(i, 0, LEN(v) - 2) {
			maxi = v[i + 1].first - v[i].first;
			t = K / v[i].second;
			K -= min(maxi, t) * v[i].second;
			ans += min(maxi, t);
			v[i + 1].second += v[i].second;
			if (maxi > t) break;
		}
		if (maxi <= t) {
			t = K / v[LEN(v) - 1].second;
			ans += t;
		}

		cout << ans;
	}

	return 0;
}