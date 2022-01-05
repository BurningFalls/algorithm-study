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

ll Gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}

int main() {
	FASTIO;
	int K, N;
	cin >> K >> N;
	ll lcm = 1;
	FOR(i, 0, N - 1) {
		ll num;
		cin >> num;
		if (i == 0) {
			lcm = num;
		}
		else {
			lcm = lcm * num / Gcd(lcm, num);
		}
	}
	cout << lcm - K;

	return 0;
}