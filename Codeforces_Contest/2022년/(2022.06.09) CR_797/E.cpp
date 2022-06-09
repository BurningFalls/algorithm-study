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
#define INF int(2e9)
#define LINF ll(1e18)

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		vector<ll> A(N);
		vector<ll> cnt(1000, 0);
		FOR(i, 0, N - 1) {
			cin >> A[i];
		}
		ll ans = 0;
		FOR(i, 0, N - 1) {
			ans += A[i] / K;
			cnt[A[i] % K]++;
		}
		int left = 1, right = K - 1;
		ll Lrest = 0, Rrest = 0;
		while (left < right) {
			Lrest = cnt[left];
			Rrest += cnt[right];
			int used = min(Lrest, Rrest);
			ans += used;
			Lrest -= used;
			Rrest -= used;
			left++;
			right--;
		}
		if (left == right) {
			Rrest += cnt[right];
		}
		ans += Rrest / 2;
		cout << ans << "\n";
	}

	return 0;
}