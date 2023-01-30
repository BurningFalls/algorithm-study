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
	int N, M;
	cin >> N >> M;
	vector<vector<ll>> P(N, vector<ll>(M));
	vector<ll> ans(N);
	FOR(j, 0, M - 1) {
		FOR(i, 0, N - 1) {
			cin >> P[i][j];
		}
	}

	ll sum = 0;
	FOR(i, 0, N - 1) {
		sort(ALL(P[i]));
		ans[i] = P[i][M / 2];
		FOR(j, 0, M - 1) {
			sum += abs(ans[i] - P[i][j]);
		}
	}

	cout << sum << "\n";
	FOR(i, 0, N - 1) {
		cout << ans[i] << " ";
	}

	return 0;
}