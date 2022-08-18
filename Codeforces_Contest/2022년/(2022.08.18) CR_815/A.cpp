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
	int T;
	cin >> T;
	while (T--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		ll t1 = a * d;
		ll t2 = b * c;
		if (t1 == t2) {
			cout << 0;
		}
		else if (t1 == 0 || t2 == 0 || t1 % t2 == 0 || t2 % t1 == 0) {
			cout << 1;
		}
		else {
			cout << 2;
		}
		cout << "\n";
	}

	return 0;
}