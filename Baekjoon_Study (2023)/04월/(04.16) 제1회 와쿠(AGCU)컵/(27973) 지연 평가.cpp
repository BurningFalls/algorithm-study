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
	int Q;
	cin >> Q;
	ll num = 1;
	ll add = 0, multi = 1;
	FOR(q, 1, Q) {
		ll k, x, n;
		cin >> k;
		if (k == 0) {
			cin >> x;
			add += x;
		}
		else if (k == 1) {
			cin >> x;
			multi *= x;
			add *= x;
		}
		else if (k == 2) {
			cin >> n;
			num += n;
		}
		else if (k == 3) {
			cout << num * multi + add << "\n";
		}
	}

	return 0;
}