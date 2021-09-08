#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())
#define MOD 998244353

int A[200001];
ll factorial[200001];

int main() {
	FASTIO;
	factorial[0] = 1;
	FOR(i, 1, 200000)
		factorial[i] = (factorial[i - 1] * i) % MOD;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int maxi = 0;
		FOR(i, 1, N) {
			cin >> A[i];
			maxi = max(maxi, A[i]);
		}
		int maxi_cnt = 0;
		int maxi2_cnt = 0;
		FOR(i, 1, N) {
			if (A[i] == maxi)
				maxi_cnt++;
			else if (A[i] == maxi - 1)
				maxi2_cnt++;
		}
		if (maxi_cnt >= 2) {
			cout << factorial[N];
		}
		else {
			ll ans = 0;
			int rest = N - 1 - maxi2_cnt;
			ROF(i, rest, 0) {
				ll tmp = factorial[i + maxi2_cnt] * factorial[rest];
				tmp /= factorial[i];
				tmp = tmp % MOD;
				ans = (ans + tmp) % MOD;
			}
			ans = (factorial[N] - ans + MOD) % MOD;
			cout << ans;
		}
		cout << "\n";
	}

	return 0;
}