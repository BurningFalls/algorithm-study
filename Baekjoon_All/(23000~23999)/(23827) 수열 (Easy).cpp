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
#define MOD 1000000007

int main() {
	FASTIO;
	ll N;
	cin >> N;
	vector<ll> v(N);
	ll sum = 0;
	ll ans = 0;
	FOR(i, 0, N - 1) {
		cin >> v[i];
		sum += v[i];
	}
	
	FOR(i, 0, N - 2) {
		sum -= v[i];
		ans = (ans + v[i] * sum) % MOD;
	}
	cout << ans;


	return 0;
}