#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int CCW(pll a, pll b, pll c) {
	ll t1 = a.first * b.second + b.first * c.second + c.first * a.second;
	ll t2 = a.second * b.first + b.second * c.first + c.second * a.first;
	if (t1 - t2 > 0)
		return 1;
	else if (t1 - t2 == 0)
		return 0;
	else if (t1 - t2 < 0)
		return -1;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<ll> v(N);
	vector<int> ans(N, 0);
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}
	FOR(i, 0, N - 2) {
		pll a = { i, v[i] };
		pll b = { i + 1, v[i + 1] };
		ans[i]++;
		ans[i + 1]++;
		FOR(j, i + 2, N - 1) {
			pll c = { j, v[j] };
			int ccw = CCW(a, b, c);
			if (ccw == 1) {
				ans[i]++;
				ans[j]++;
				b = c;
			}
		}
	}
	int maxi = 0;
	FOR(i, 0, N - 1) {
		maxi = max(maxi, ans[i]);
	}
	cout << maxi;

	return 0;
}