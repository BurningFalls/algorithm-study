#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll X, Y;
	cin >> X >> Y;
	ll Z = (Y * 100) / X;
	if (Z == 99 || Z == 100)
		cout << -1;
	else {
		ll ans = -1;
		ll left = 1, right = X;
		while (left <= right) {
			ll mid = (left + right) / 2;
			ll score = ((Y + mid) * 100) / (X + mid);
			if (score >= Z + 1) {
				right = mid - 1;
				ans = mid;
			}
			else {
				left = mid + 1;
			}
		}
		cout << ans;
	}

	return 0;
}