#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<ll> v;
ll arr[16];

int main() {
	FASTIO;
	ll N, W;
	cin >> N >> W;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	v.push_back(arr[1]);
	FOR(i, 2, N) {
		if (v.back() == arr[i]) continue;
		v.push_back(arr[i]);
	}
	int vlen = v.size();
	ll coin = 0;
	ll ans = W;
	if (vlen != 1 && v[0] < v[1]) {
		ll tmp = ans / v[0];
		coin += tmp;
		ans -= tmp * v[0];
	}
	FOR(i, 1, vlen - 2) {
		if (v[i - 1] > v[i] && v[i] < v[i + 1]) {
			ll tmp = ans / v[i];
			coin += tmp;
			ans -= tmp * v[i];
		}
		else if (v[i - 1] < v[i] && v[i] > v[i + 1]) {
			ans += coin * v[i];
			coin = 0;
		}
	}
	ans += coin * v[vlen - 1];

	cout << ans;

	return 0;
}