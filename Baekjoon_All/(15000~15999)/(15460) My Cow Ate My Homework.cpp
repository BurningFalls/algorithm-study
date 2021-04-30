#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll arr[100002];
ll sum[100002];
ll mini[100002];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	sum[N + 1] = 0;
	ROF(i, N, 1) {
		sum[i] = sum[i + 1] + arr[i];
	}
	mini[N] = arr[N];
	ROF(i, N - 1, 1) {
		mini[i] = min(mini[i + 1], arr[i]);
	}
	ll maxi_up = 0, maxi_down = 0;
	FOR(K, 1, N - 2) {
		ll tmp = sum[K + 1] - mini[K + 1];
		ll cnt = (ll)N - K - 1;
		if (K == 1) {
			maxi_up = tmp;
			maxi_down = cnt;
		}
		else {
			if (maxi_up * cnt < maxi_down * tmp) {
				maxi_up = tmp;
				maxi_down = cnt;
			}
		}
	}
	FOR(K, 1, N - 2) {
		ll tmp = sum[K + 1] - mini[K + 1];
		ll cnt = (ll)N - K - 1;
		if (maxi_up * cnt == maxi_down * tmp) {
			cout << K << "\n";
		}
	}

	return 0;
}