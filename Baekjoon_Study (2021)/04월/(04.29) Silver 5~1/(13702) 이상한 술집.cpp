#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll arr[10001];

int main() {
	FASTIO;
	ll N, K;
	cin >> N >> K;
	ll maxi = 0;
	FOR(i, 1, N) {
		cin >> arr[i];
		maxi = max(maxi, arr[i]);
	}
	ll left = 0, right = maxi;
	ll ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;
		if (mid == 0)
			sum = 0;
		else {
			FOR(i, 1, N)
				sum += arr[i] / mid;
		}
		if (sum >= K) {
			left = mid + 1;
			ans = max(ans, mid);
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans;

	return 0;
}