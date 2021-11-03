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
	int T;
	cin >> T;
	while (T--) {
		ll x, n;
		cin >> x >> n;
		ll add = 0;
		if (abs(x) % 2 == 0) {
			if (n % 4 == 0)
				add = 0;
			else if (n % 4 == 1)
				add = -n;
			else if (n % 4 == 2)
				add = 1;
			else if (n % 4 == 3)
				add = n + 1;
			cout << x + add << "\n";
		}
		else if (abs(x) % 2 == 1) {
			if (n % 4 == 0)
				add = 1;
			else if (n % 4 == 1)
				add = n + 1;
			else if (n % 4 == 2)
				add = 0;
			else if (n % 4 == 3)
				add = -n;
			cout << x - 1 + add << "\n";
		}
	}


	return 0;
}