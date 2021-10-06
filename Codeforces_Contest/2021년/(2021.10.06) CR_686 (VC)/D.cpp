#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		ll N;
		cin >> N;
		ll X = N;
		ll sqrtx = sqrt(X);
		ll maxi_num = 0;
		ll maxi_cnt = 0;
		FOR(i, 2, sqrtx) {
			if (X % i != 0) continue;
			int cnt = 0;
			while (X % i == 0) {
				X /= i;
				cnt++;
			}
			if (maxi_cnt < cnt) {
				maxi_cnt = cnt;
				maxi_num = i;
			}
		}
		if (maxi_cnt == 0) {
			cout << 1 << "\n" << N << "\n";
		}
		else {
			cout << maxi_cnt << "\n";
			FOR(i, 1, maxi_cnt - 1)
				cout << maxi_num << " ";
			cout << N / ll(pow(maxi_num, maxi_cnt - 1)) << "\n";
		}
	}

	return 0;
}