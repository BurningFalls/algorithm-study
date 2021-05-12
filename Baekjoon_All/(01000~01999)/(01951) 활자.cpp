#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1234567

ll arr[11];

int main() {
	FASTIO;
	arr[0] = 0;
	FOR(i, 1, 10)
		arr[i] = arr[i - 1] + (ll)i * 9 * pow(10, i - 1);
	ll ans = 0;
	ll N;
	cin >> N;
	string s = to_string(N);
	int len = s.size();
	ans += arr[len - 1];
	ans += (N - pow(10, len - 1) + 1) * len;
	cout << ans % MOD;

	return 0;
}