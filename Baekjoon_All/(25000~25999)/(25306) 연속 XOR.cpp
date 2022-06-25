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

ll Xor(ll n) {
	ll m = n % 4;
	if (m == 0) return n;
	if (m == 1) return 1;
	if (m == 2) return n + 1;
	return 0;
}

int main() {
	FASTIO;
	ll A, B;
	cin >> A >> B;
	cout << (Xor(A - 1) ^ Xor(B));

	return 0;
}