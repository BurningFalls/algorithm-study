#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int
#define MOD 1000000007

ll arr[65];

ll Calc(ll x, ll y) {
	return ((x % MOD) * (y % MOD)) % MOD;
}

string Ch(ll x) {
	string ans = "";
	while (x != 0) {
		ans += x % 2;
		x /= 2;
	}
	return ans;
}

int main() {
	FASTIO;
	ll A, X, ans = 1;
	cin >> A >> X;
	arr[1] = A;
	FOR(i, 2, 64) {
		arr[i] = Calc(arr[i - 1], arr[i - 1]);
	}
	string Y = Ch(X);
	int len = Y.size();
	FOR(i, 0, len - 1) {
		if (Y[i] == 1) {
			ans = Calc(ans, arr[i + 1]);
		}
	}
	cout << ans;


	return 0;
}