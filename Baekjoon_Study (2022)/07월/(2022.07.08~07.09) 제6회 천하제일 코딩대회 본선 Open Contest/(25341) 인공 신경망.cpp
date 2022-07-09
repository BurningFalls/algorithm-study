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
#define MAX 2002

vector<ll> P(MAX), X(MAX, 0), A(MAX);
vector<vector<ll>> W(MAX, vector<ll>(MAX, 0));

int main() {
	FASTIO;
	ll N, M, Q;
	cin >> N >> M >> Q;
	FOR(i, 1, M) {
		int cnt;
		cin >> cnt;
		FOR(j, 1, cnt) {
			cin >> P[j];
		}
		P[cnt + 1] = N + 1;
		FOR(j, 1, cnt + 1) {
			cin >> W[i][P[j]];
		}
	}
	FOR(i, 1, M) {
		ll output_W;
		cin >> output_W;
		FOR(j, 1, N + 1) {
			X[j] += output_W * W[i][j];
		}
	}
	ll output_B;
	cin >> output_B;
	X[N + 1] += output_B;

	FOR(q, 1, Q) {
		FOR(i, 1, N) {
			cin >> A[i];
		}
		A[N + 1] = 1;
		ll ans = 0;
		FOR(i, 1, N + 1) {
			ans += A[i] * X[i];
		}
		cout << ans << "\n";
	}

	return 0;
}