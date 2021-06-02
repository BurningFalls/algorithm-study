#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 2100000000

int N;
int Map[101][101];
int ans;
int dy[13][3] = { {0, 0, 0}, {1, 1, 1}, {0, 1, 0}, {1, 0, 1},
{0, 0, 1}, {1, 1, 0}, {1, 0, 0}, {0, 1, 1},
{0, 0, 1}, {1, 1, -1}, {1, 0, 0}, {1, 1, -1},
{0, 1, 0} };
int dx[13][3] = { {1, 1, 1}, {0, 0, 0}, {1, 0, 1}, {0, -1, 0},
{1, 1, 0}, {0, 0, -1}, {0, 1, 1}, {-1, 0, 0},
{1, 1, -1}, {0, 0, -1}, {-1, 1, 1}, {0, 0, 1},
{1, -1, 1} };

int what[3] = { 0, };

void Do() {
	FOR(i, 0, 12) {
		FOR(y, 1, N) {
			FOR(x, 1, N) {
				int sum = Map[y][x];
				bool flag = true;
				int ny = y, nx = x;
				FOR(k, 0, 2) {
					ny += dy[i][k];
					nx += dx[i][k];
					if (ny < 1 || nx < 1 || ny > N || nx > N) {
						flag = false;
						break;
					}
					sum += Map[ny][nx];
				}
				if (flag) {
					ans = max(ans, sum);
				}
			}
		}
	}
}

int main() {
	FASTIO;
	int idx = 1;
	while (true) {
		ans = -INF;
		cin >> N;
		if (N == 0)
			break;
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				cin >> Map[i][j];
			}
		}
		Do();
		cout << idx << ". " << ans << "\n";
		idx++;
	}


	return 0;
}