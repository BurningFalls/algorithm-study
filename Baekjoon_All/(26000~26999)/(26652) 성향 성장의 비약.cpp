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

int main() {
	FASTIO;
	ll N, M;
	cin >> N >> M;
	vector<ll> L(N), A(N), maxL(N);
	ll maxi = 0;
	FOR(i, 0, N - 1) {
		cin >> L[i];
		maxi = max(maxi, L[i]);
	}
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}

	FOR(i, 0, N - 1) {
		ll left = L[i], right = 3000000000;
		ll ans = 0;
		while (left <= right) {
			ll mid = (left + right) / 2;
			ll tmp = (mid - 1) * mid / 2 - (L[i] - 1) * L[i] / 2;
			if (tmp <= A[i]) {
				ans = max(ans, mid);
				left = mid + 1;
			}
			else if (tmp > A[i]) {
				right = mid - 1;
			}
		}
		maxL[i] = ans;
	}

	ll left = maxi, right = 1000000000000;
	ll ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;
		FOR(i, 0, N - 1) {
			sum += max(0LL, mid - maxL[i]);
		}
		if (sum <= M) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else if (sum > M) {
			right = mid - 1;
		}
	}
	cout << (ans == 0 ? -1 : ans);

	return 0;
}