#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}
	sort(ALL(v));

	ll ans = 0;
	FOR(i, 0, N - 1) {
		if (v[i] > 0) break;
		FOR(j, i + 1, N - 1) {
			int num = -v[i] - v[j];
			if (num < v[j]) break;
			int lb = lower_bound(v.begin() + j + 1, v.end(), num) - v.begin();
			int ub = upper_bound(v.begin() + j + 1, v.end(), num) - v.begin();
			ans += (ub - lb);
		}
	}
	cout << ans;

	return 0;
}