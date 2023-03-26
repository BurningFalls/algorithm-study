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
	int N, Q;
	cin >> N >> Q;
	vector<vector<ll>> A(N + 2, vector<ll>(N + 2, 0));
	vector<vector<ll>> mini(N + 2, vector<ll>(N + 2, 0));
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> A[i][j];
		}
	}
	FOR(i, 1, N) {
		ROF(j, N - 1, 1) {
			A[i][j] = A[i][j + 1] + A[i][j];
		}
	}
	FOR(j, 1, N) {
		mini[1][j] = A[1][j];
		FOR(i, 2, N) {
			mini[i][j] = min(mini[i - 1][j], A[i][j]);
		}
	}

	FOR(q, 1, Q) {
		int sx, sy, L;
		cin >> sx >> sy >> L;
		ll ans = LINF;
		FOR(j, sy - 1, N) {
			ll tmp = A[sx][sy] - A[sx][j + 1];
			tmp += mini[sx - L][j + 1];
			ans = min(ans, tmp);
		}
		cout << ans << "\n";
	}

	return 0;
}