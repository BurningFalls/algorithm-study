#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll arr[38];

ll Func(ll x) {
	int idx = 0;
	ll ans = 0;
	while (x != 0) {
		int tmp = x % 2;
		ans += tmp * arr[idx];
		x /= 2;
		idx++;
	}
	return ans;
}

int main() {
	FASTIO;
	arr[0] = 1;
	FOR(i, 1, 37)
		arr[i] = arr[i - 1] * 3;
	int T;
	cin >> T;
	while (T--) {
		ll N;
		cin >> N;
		cout << Func(N) << "\n";
	}


	return 0;
}