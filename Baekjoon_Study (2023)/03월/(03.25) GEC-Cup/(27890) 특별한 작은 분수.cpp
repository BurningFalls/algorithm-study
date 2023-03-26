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
	ll x, N;
	cin >> x >> N;
	FOR(t, 1, N) {
		if (x % 2 == 0) {
			x = (x / 2) ^ 6;
		}
		else if (x % 2 == 1) {
			x = (2 * x) ^ 6;
		}
	}
	cout << x;

	return 0;
}