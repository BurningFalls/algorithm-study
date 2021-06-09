#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll X[1000001];
ll SUM[1000001];

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	SUM[0] = 0;
	FOR(i, 1, N)
		cin >> X[i];
	sort(X + 1, X + N + 1);
	FOR(i, 1, N)
		SUM[i] = SUM[i - 1] + X[i];
	int left = X[1], right = X[N];
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int lb = lower_bound(X + 1, X + N + 1, mid) - X;
		ll sum = (ll)mid * ((ll)lb - 1) - SUM[lb - 1];
		if (sum <= K) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << ans;

	return 0;
}