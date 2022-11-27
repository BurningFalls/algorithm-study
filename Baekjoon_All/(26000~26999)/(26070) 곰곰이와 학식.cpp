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
	vector<ll> A(3), B(3);
	FOR(i, 0, 2) {
		cin >> A[i];
	}
	FOR(i, 0, 2) {
		cin >> B[i];
	}
	ll cnt = 0;
	FOR(i, 0, 6) {
		if (A[i % 3] <= B[i % 3]) {
			ll tmp = ((B[i % 3] - A[i % 3]) / 3);
			B[(i + 1) % 3] += tmp;
			B[i % 3] -= tmp * 3;
		}
		ll tmp = min(A[i % 3], B[i % 3]);
		cnt += tmp;
		A[i % 3] -= tmp;
		B[i % 3] -= tmp;
	}
	cout << cnt;

	return 0;
}