#include <bits/stdc++.h>
using namespace std;

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
	int T, K;
	cin >> T >> K;
	vector<int> l(5);
	vector<vector<int>> a(5);
	FOR(i, 0, 4) {
		cin >> l[i];
		a[i] = vector<int>(l[i] + 1, 0);
		FOR(j, 1, l[i]) {
			cin >> a[i][j];
		}
	}
	vector<int> M(3);
	vector<vector<int>> c(3);
	vector<vector<vector<int>>> v(3);
	FOR(i, 0, 2) {
		cin >> M[i];
		c[i] = vector<int>(M[i] + 1, 0);
		FOR(j, 1, M[i]) {
			cin >> c[i][j];
		}
		v[i] = vector<vector<int>>(M[i] + 1, vector<int>(5, 0));
		FOR(j, 1, M[i]) {
			FOR(k, 0, 4) {
				cin >> v[i][j][k];
			}
		}
	}

	int maxi = 0;
	FOR(i, 0, M[0]) {
		FOR(j, 0, M[1]) {
			FOR(k, 0, M[2]) {
				int price = c[0][i] + c[1][j] + c[2][k];
				if (price > T) continue;
				vector<int> level(5);
				FOR(n, 0, 4) {
					level[n] = v[0][i][n] + v[1][j][n] + v[2][k][n];
				}
				int ans1 = 0, ans2 = 0;
				FOR(n, 0, 4) {
					ans1 += a[n][min(l[n], level[n])];
				}
				if (price + K <= T) {
					FOR(x, 0, 4) {
						if (level[x] == 0) continue;
						level[x]--;
						FOR(y, 0, 4) {
							if (x == y) continue;
							level[y]++;
							int tmp = 0;
							FOR(n, 0, 4) {
								tmp += a[n][min(l[n], level[n])];
							}
							ans2 = max(ans2, tmp);
							level[y]--;
						}
						level[x]++;
					}
				}
				maxi = max(maxi, max(ans1, ans2));
			}
		}
	}
	cout << maxi;

	return 0;
}