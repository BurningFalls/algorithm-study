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
		ll R, C;
		cin >> R >> C;
		ll K = min(R, C) - 1;
		ll tmp = (K * (K + 1) * (2 * K + 1)) / 3 + (1 - R - C) * K * (K + 1) + (2 * R * C - R - C) * (K + 1);
		cout << tmp + (K + 1) << " " << tmp << "\n";
	}


	return 0;
}