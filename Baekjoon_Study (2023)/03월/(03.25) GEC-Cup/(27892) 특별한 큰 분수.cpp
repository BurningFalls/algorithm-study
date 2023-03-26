#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	ll x, N;
	cin >> x >> N;
	map<ll, ll> mp;
	vector<ll> v;
	mp[x] = 0;
	v.push_back(x);
	ll idx = 1;
	ll rest = 0;
	while (idx <= N) {
		if (x % 2 == 0) {
			x = (x / 2) ^ 6;
		}
		else if (x % 2 == 1) {
			x = (2 * x) ^ 6;
		}
		if (mp.count(x)) {
			rest = N - idx;
			idx = mp[x];
			break;
		}
		mp[x] = idx;
		v.push_back(x);
		idx++;
	}

	if (rest == 0) {
		cout << x;
	}
	else {
		ll len = LEN(v);
		rest = rest % (len - idx);
		idx += rest;
		cout << v[idx];
	}

	return 0;
}