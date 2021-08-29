#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
ll K;
ll arr[200001];

ll BS(ll a, ll b) {
	if (a > b)
		swap(a, b);
	ll left = 0, right = K;
	ll ans = 1000000000000000001;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll A = ((mid % a == 0) ? mid / a : mid / a + 1);
		ll B = (((K - mid) % b == 0) ? (K - mid) / b : (K - mid) / b + 1);
		ans = min(ans, max(A, B));
		if (A < B) {
			left = mid + 1;
		}
		else if (A > B) {
			right = mid - 1;
		}
		else if (A == B) {
			break;
		}
	}
	return ans;
}

int main() {
	FASTIO;
	cin >> N >> K;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	ll maxi = 0;
	int idx = 0;
	ll ans = 1000000000000000001;
	FOR(i, 1, N - 1) {
		ll A = arr[1] * i;
		ll B = arr[i + 1] * ((ll)N - i);
		ans = min(ans, BS(A, B));
	}
	cout << ans;

	return 0;
}