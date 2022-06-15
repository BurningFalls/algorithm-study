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
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		vector<int> A(N);
		vector<int> check(N, 0);
		vector<int> cnt(N, 0);
		FOR(i, 0, N - 1) {
			cin >> A[i];
		}
		FOR(i, 1, N - 1) {
			if (A[i - 1] < 2 * A[i]) {
				check[i] = 1;
			}
		}

		FOR(i, 0, N - 1) {
			if (check[i]) {
				cnt[i] = cnt[i - 1] + 1;
			}
			else if (!check[i]) {
				cnt[i] = 1;
			}
		}
		
		int ans = 0;
		FOR(i, 0, N - 1) {
			ans += (cnt[i] >= K + 1);
		}
		cout << ans << "\n";
	}

	return 0;
}