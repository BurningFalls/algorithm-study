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
	ll N, M, K;
	cin >> N >> M >> K;
	vector<ll> L(N);
	FOR(i, 0, N - 1) {
		cin >> L[i];
	}
	sort(ALL(L));

	int left = 1, right = N;
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		ll sum = 0;
		for (int i = mid - 1; i >= 0; i -= K) {
			sum += L[i];
		}
		if (sum <= M) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else if (sum > M) {
			right = mid - 1;
		}
	}
	cout << ans;

	return 0;
}