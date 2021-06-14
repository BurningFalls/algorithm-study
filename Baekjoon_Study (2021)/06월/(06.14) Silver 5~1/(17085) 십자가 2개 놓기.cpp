#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
char Cross[8][16][16];
char Map[16][16];
bool visited[16][16] = { 0, };
int ans = 1;

bool is_Possible(int sy, int sx, int k, bool dont) {
	int size = k * 2 + 1;
	bool flag = true;
	FOR(i, 1, size) {
		FOR(j, 1, size) {
			if (Cross[k][i][j] == '*') {
				if (Map[sy + i - 1][sx + j - 1] == '.' || visited[sy + i - 1][sx + j - 1])
					flag = false;
				if (!dont)
					visited[sy + i - 1][sx + j - 1] = 1;
			}
		}
	}
	return flag;
}

void Print() {
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cout << visited[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	FOR(k, 0, 7) {
		int size = 2 * k + 1;
		FOR(i, 1, size) {
			FOR(j, 1, size) {
				Cross[k][i][j] = '.';
			}
		}
		FOR(i, 1, size) {
			Cross[k][size / 2 + 1][i] = '*';
			Cross[k][i][size / 2 + 1] = '*';
		}
	}
	bool flag, flag2;
	FOR(k1, 0, 7) {
		int size = k1 * 2 + 1;
		FOR(i, 1, N + 1 - size) {
			FOR(j, 1, M + 1 - size) {
				memset(visited, 0, sizeof(visited));
				flag = is_Possible(i, j, k1, false);
				if (!flag) continue;
				FOR(k2, k1, 7) {
					int size2 = k2 * 2 + 1;
					FOR(i2, 1, N + 1 - size2) {
						FOR(j2, 1, M + 1 - size2) {
							flag2 = is_Possible(i2, j2, k2, true);
							if (flag2) {
								int tmp1 = k1 * 4 + 1;
								int tmp2 = k2 * 4 + 1;
								ans = max(ans, tmp1 * tmp2);
							}
						}
					}
				}
			}
		}
	}
	cout << ans;

	return 0;
}