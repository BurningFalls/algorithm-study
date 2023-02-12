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
	while (true) {
		int N;
		cin >> N;
		if (N == 0) break;
		if (N == 1) {
			cout << 0 << "\n";
			continue;
		}
		int ans = N;
		int n = N;
		for (int i = 2; i * i <= n; i++) {
			if (N % i == 0) {
				ans -= ans / i;
				while (N % i == 0) {
					N /= i;
				}
			}
		}
		if (N > 1) {
			ans -= ans / N;
		}
		cout << ans << "\n";
	}

	return 0;
}