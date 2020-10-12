#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll ans[10] = { 0, };

void calc(ll n, ll ten) {
	while (n > 0) {
		ans[n % 10] += ten;
		n /= 10;
	}
}

void func(ll start, ll end, ll ten) {
	while (start % 10 != 0 && start <= end) {
		calc(start, ten);
		start += 1;
	}
	if (start > end)
		return;
	while (end % 10 != 9 && start <= end) {
		calc(end, ten);
		end -= 1;
	}
	ll cnt = (end / 10 - start / 10 + 1);
	FOR(i, 0, 9) {
		ans[i] += cnt * ten;
	}
	func(start / 10, end / 10, ten * 10);
}

int main() {
	FASTIO;
	ll N;
	cin >> N;
	func(1, N, 1);
	FOR(i, 0, 9)
		cout << ans[i] << " ";

	return 0;
}