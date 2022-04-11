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
	ll N;
	cin >> N;
	ll ans = 0;
	ll right = 1;
	ll num = 1;
	while (num < N) {
		right = (N - 1) / ((N - 1) / num);
		ll cnt = (N - 1) / num + 1;
		ans += (right - num + 1) * cnt;
		num = right + 1;
	}
	cout << ans + 1;

	return 0;
}