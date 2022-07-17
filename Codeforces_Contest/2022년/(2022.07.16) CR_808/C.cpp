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
		int N, Q;
		cin >> N >> Q;
		vector<int> A(N);
		vector<int> ans(N, 0);
		FOR(i, 0, N - 1) {
			cin >> A[i];
		}

		int q = 0;
		ROF(i, N - 1, 0) {
			if (q < A[i] && q < Q) {
				ans[i] = 1;
				q++;
			}
			else if (q >= A[i]) {
				ans[i] = 1;
			}
		}

		FOR(i, 0, N - 1) {
			cout << ans[i];
		}
		cout << "\n";
	}

	return 0;
}