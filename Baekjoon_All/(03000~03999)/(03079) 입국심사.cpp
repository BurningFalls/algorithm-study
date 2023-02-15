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
	vector<ll> T(N);
	FOR(i, 0, N - 1) {
		cin >> T[i];
	}
	ll ans = LINF;
	ll left = 0, right = LINF;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;
		FOR(i, 0, N - 1) {
			if (sum > LINF) break;
			sum += mid / T[i];
		}
		if (sum >= M) {
			ans = min(ans, mid);
			right = mid - 1;
		}
		else if (sum < M) {
			left = mid + 1;
		}
	}
	cout << ans;

	return 0;
}