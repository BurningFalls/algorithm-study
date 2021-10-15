#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<ll> cnt(M, 0);
	int sum = 0;
	FOR(i, 0, N - 1) {
		int num;
		cin >> num;
		sum = (sum + num) % M;
		cnt[sum]++;
	}
	ll ans = cnt[0];
	FOR(i, 0, M - 1) {
		if (cnt[i] <= 1) continue;
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}
	cout << ans;

	return 0;
}