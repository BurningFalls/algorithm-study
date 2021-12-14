#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	ll D, N, M, K;
	cin >> D;
	cin >> N >> M >> K;
	ll maxi_bok = 0, maxi_gun = 0;
	ll add1 = D - N % D;
	ll add2 = D - M % D;
	pll adding[4] = { {0, 0}, {add1, 0}, {0, add2}, {add1, add2} };
	FOR(i, 0, 3) {
		ll a1 = adding[i].first;
		ll a2 = adding[i].second;
		ll tmp = (N + a1) / D + (M + a2) / D + (K - a1 - a2) / D;
		if (maxi_gun < tmp) {
			maxi_gun = tmp;
			maxi_bok = (K - a1 - a2);
		}
		else if (maxi_gun == tmp) {
			maxi_bok = max(maxi_bok, K - a1 - a2);
		}
	}
	cout << maxi_bok;

	return 0;
}