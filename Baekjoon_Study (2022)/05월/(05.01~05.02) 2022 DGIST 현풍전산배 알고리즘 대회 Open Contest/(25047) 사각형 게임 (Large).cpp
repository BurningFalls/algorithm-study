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
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<vector<ll>> Map(N, vector<ll>(N));
	vector<ll> row_sum(N, 0);
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			cin >> Map[i][j];
			row_sum[i] += Map[i][j];
		}
	}

	ll max_o_score = -LINF;
	int set_k = 0;
	FOR(k, 0, (1 << N) - 1) {
		ll o_score = 0;
		ll total_t_ben = 0;
		FOR(i, 0, N - 1) {
			if (k & (1 << i)) {
				o_score += row_sum[i];
			}
		}
		FOR(j, 0, N - 1) {
			ll o_ben = 0;
			ll t_ben = 0;
			FOR(i, 0, N - 1) {
				if (k & (1 << i)) {
					o_ben -= Map[i][j];
					t_ben += Map[i][j];
				}
				else {
					o_ben += Map[i][j];
					t_ben -= Map[i][j];
				}
			}
			if (t_ben > 0) {
				o_score += o_ben;
				total_t_ben += t_ben;
			}
		}
		max_o_score = max(max_o_score, o_score);
	}

	cout << max_o_score;

	return 0;
}