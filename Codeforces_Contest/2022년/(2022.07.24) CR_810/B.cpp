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
		int N, M;
		cin >> N >> M;
		vector<int> A(N + 1);
		vector<pii> Edge(M);
		vector<int> cnt(N + 1, 0);
		int ans = 0;
		FOR(i, 1, N) {
			cin >> A[i];
			ans += A[i];
		}
		FOR(i, 0, M - 1) {
			int x, y;
			cin >> x >> y;
			Edge[i] = { x, y };
			cnt[x]++; cnt[y]++;
		}
		if (M % 2 == 0) {
			ans = 0;
		}
		else if (M % 2 == 1) {
			FOR(i, 1, N) {
				if (cnt[i] % 2 == 1) {
					ans = min(ans, A[i]);
				}
			}
			FOR(i, 0, M - 1) {
				int x = Edge[i].first;
				int y = Edge[i].second;
				if (cnt[x] % 2 == cnt[y] % 2) {
					ans = min(ans, A[x] + A[y]);
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}