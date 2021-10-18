#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int main() {
	FASTIO;
	int N;
	cin >> N;
	vvi idx(6, vi());
	idx[0] = { 1, 2, 3, 4, 5 };
	idx[1] = { 0, 2, 4, 5, 3 };
	idx[2] = { 0, 1, 3, 5, 4 };
	idx[3] = { 0, 2, 4, 5, 1 };
	idx[4] = { 0, 1, 3, 5, 2 };
	idx[5] = { 1, 2, 3, 4, 0 };
	vvi num(N, vi(6));
	vvi rest(N);
	FOR(i, 0, N - 1) {
		FOR(j, 0, 5) {
			cin >> num[i][j];
		}
	}
	int ans = 0;
	FOR(start, 1, 6) {
		int cur = 0;
		FOR(i, 0, 5) {
			if (num[0][i] == start) {
				cur = i;
			}
		}
		fill(ALL(rest), vi(4, 0));
		FOR(i, 0, N - 1) {
			FOR(j, 0, 3) {
				rest[i][j] = num[i][idx[cur][j]];
			}
			int tmp = num[i][idx[cur][4]];
			if (i == N - 1) continue;
			FOR(j, 0, 5) {
				if (num[i + 1][j] == tmp) {
					cur = j;
				}
			}
		}
		int sum = 0;
		FOR(i, 0, N - 1) {
			int maxi = 0;
			FOR(j, 0, 3) {
				maxi = max(maxi, rest[i][j]);
			}
			sum += maxi;
		}
		ans = max(ans, sum);
	}
	cout << ans;

	return 0;
}