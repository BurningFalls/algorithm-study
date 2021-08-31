#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		int small_idx = 0;
		int big_idx = 0;
		cin >> N;
		FOR(i, 1, N) {
			int num;
			cin >> num;
			if (num == 1)
				small_idx = i;
			else if (num == N)
				big_idx = i;
		}
		int ans = 101;
		ans = min(ans, max(small_idx, big_idx));
		ans = min(ans, max(N - small_idx + 1, N - big_idx + 1));
		ans = min(ans, min(small_idx, N - small_idx + 1) + min(big_idx, N - big_idx + 1));
		cout << ans << "\n";
	}


	return 0;
}