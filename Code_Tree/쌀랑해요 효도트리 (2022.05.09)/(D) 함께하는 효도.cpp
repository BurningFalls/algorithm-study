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
	int N, M;
	cin >> N >> M;
	vector<vector<int>> v(N, vector<int>(N));
	vector<vector<int>> check;
	vector<pii> pos(M);
	int moving[64][3];
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };

	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			cin >> v[i][j];
		}
	}

	FOR(a, 0, 3) {
		FOR(b, 0, 3) {
			FOR(c, 0, 3) {
				moving[16 * a + 4 * b + c][0] = a;
				moving[16 * a + 4 * b + c][1] = b;
				moving[16 * a + 4 * b + c][2] = c;
			}
		}
	}

	FOR(m, 0, M - 1) {
		int x, y;
		cin >> x >> y;
		pos[m] = { x - 1, y - 1 };
	}

	int maxi = 0;

	FOR(a, 0, 63) {
		FOR(b, 0, 63) {
			FOR(c, 0, 63) {
				check = vector<vector<int>>(N, vector<int>(N, 0));
				vector<int> tmp = { a, b, c };
				int sum = 0;
				FOR(p, 0, M - 1) {
					int y = pos[p].first;
					int x = pos[p].second;
					if (check[y][x] != 1) {
						check[y][x] = 1;
						sum += v[y][x];
					}
					check[y][x] = 1;
					FOR(k, 0, 2) {
						int m = moving[tmp[p]][k];
						y += dy[m];
						x += dx[m];
						if (y < 0 || x < 0 || y >= N || x >= N) break;
						if (check[y][x] != 1) {
							check[y][x] = 1;
							sum += v[y][x];
						}
					}
				}
				maxi = max(maxi, sum);
			}
		}
	}

	cout << maxi;

	return 0;
}