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
	vector<vector<int>> D(N, vector<int>(M));
	vector<int> col_sum(M, 0), row_sum(N, 0);
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> D[i][j];
		}
	}
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			row_sum[i] += D[i][j];
		}
	}
	FOR(j, 0, M - 1) {
		FOR(i, 0, N - 1) {
			col_sum[j] += D[i][j];
		}
	}

	int maxi = -INF;
	FOR(a, 0, N - 1) {
		FOR(b, a + 1, N - 1) {
			FOR(c, 0, M - 1) {
				FOR(d, c + 1, M - 1) {
					int sum = row_sum[a] + row_sum[b] + col_sum[c] + col_sum[d];
					sum -= D[a][c] + D[a][d] + D[b][c] + D[b][d];
					sum += (b - a - 1) * (d - c - 1);
					maxi = max(maxi, sum);
				}
			}
		}
	}
	cout << maxi;

	return 0;
}