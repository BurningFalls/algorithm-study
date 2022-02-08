#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> v(N);
	vector<vector<ll>> cnt(20, vector<ll>(2, 0));
	for (int& x : v) {
		cin >> x;
	}
	for (int x : v) {
		FOR(i, 0, 19) {
			bool flag = x & (1 << i);
			cnt[i][flag]++;
		}
	}
	ll ans = 0;
	FOR(i, 0, 19) {
		ans += (cnt[i][0] * cnt[i][1]) * (1LL << i);
	}
	cout << ans;

	return 0;
}