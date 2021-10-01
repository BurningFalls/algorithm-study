#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())
#define MOD 14579

int main() {
	FASTIO;
	ll a, b;
	cin >> a >> b;
	ll ans = 1;
	FOR(i, a, b) {
		ans = (ans * (i * (i + 1) / 2)) % MOD;
	}
	cout << ans;

	return 0;
}