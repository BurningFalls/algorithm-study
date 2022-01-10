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
	ll N;
	cin >> N;
	ll r = 2, n = 3, tmp = 1;
	bool flag = false;
	while (r <= 1000000) {
		tmp = r * r * r;
		n = 3;
		while (n <= 40) {
			if (N * (r - 1) % (tmp - 1) == 0) {
				flag = true;
				break;
			}
			if (tmp > 1e12) {
				break;
			}
			tmp *= r;
			n++;
		}
		if (flag) {
			break;
		}
		r++;
	}
	if (!flag) {
		cout << -1;
	}
	else {
		cout << n << "\n";
		ll a = N * (r - 1) / (tmp - 1);
		FOR(i, 1, n) {
			cout << a << " ";
			a *= r;
		}
	}


	return 0;
}