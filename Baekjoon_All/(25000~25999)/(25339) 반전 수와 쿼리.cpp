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
	int N, Q;
	cin >> N >> Q;
	int ans = 0;
	FOR(q, 1, Q) {
		int a;
		ll l, r;
		cin >> a >> l >> r;
		if (a == 1) {
			ans = 1 - ans;
		}
		else if (a == 2) {
			int len = r - l + 1;
			len /= 2;
			ans = (len % 2 == 0 ? ans : 1 - ans);
		}
		cout << ans << "\n";
	}

	return 0;
}