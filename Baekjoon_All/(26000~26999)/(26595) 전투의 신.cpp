#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
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
	ll N;
	cin >> N;
	ll A, PA, B, PB;
	cin >> A >> PA >> B >> PB;

	ll maxi = 0;
	ll maxx = 0, maxy = 0;
	FOR(x, 0, N / PA) {
		ll y = (N - PA * x) / PB;
		if (maxi < A * x + B * y) {
			maxi = A * x + B * y;
			maxx = x;
			maxy = y;
		}
	}
	cout << maxx << " " << maxy;

	return 0;
}