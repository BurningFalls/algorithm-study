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
	ll K, N;
	cin >> K >> N;
	if (N == 1) {
		cout << -1;
	}
	else {
		ll x = (K * N) / (N - 1);
		if ((K * N) % (N - 1) != 0) {
			x++;
		}
		cout << x;
	}


	return 0;
}