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

vector<ll> v(2000001);

int main() {
	FASTIO;
	ll N, pos;
	cin >> N;
	FOR(i, 0, N - 1) {
		ll a, c; char b;
		cin >> a >> b >> c;
		if (b == 'L') {
			v[a + 1000000] = -c;
		}
		else if (b == 'R') {
			v[a + 1000000] = c;
		}
	}
	cin >> pos;
	FOR(i, 1, N) {
		pos += v[pos + 1000000];
	}
	cout << pos;

	return 0;
}