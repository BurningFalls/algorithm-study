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
#define MOD 1000000007

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<ll> cnt(N + 1, 0);
	FOR(i, 0, N - 1) {
		int num;
		cin >> num;
		cnt[num]++;
	}
	ll ans = 1;
	FOR(i, 1, N) {
		if (cnt[i] == 0) continue;
		ans = (ans * (cnt[i] + 1)) % MOD;
	}
	cout << (ans + MOD - 1) % MOD;

	return 0;
}