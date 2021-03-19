#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char Map[101][101];
char Ans[101][101];
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {
	FASTIO;
	while (true) {
		int R, C;
		cin >> R >> C;
		if (R == 0 && C == 0)
			break;
		FOR(i, 1, R) {
			FOR(j, 1, C) {
				cin >> Map[i][j];
			}
		}
		FOR(i, 1, R) {
			FOR(j, 1, C) {
				if (Map[i][j] == '*') {
					Ans[i][j] = '*';
					continue;
				}
				int cnt = 0;
				FOR(k, 0, 7) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
					if (Map[ny][nx] == '*')
						cnt++;
				}
				Ans[i][j] = cnt + '0';
			}
		}
		FOR(i, 1, R) {
			FOR(j, 1, C) {
				cout << Ans[i][j];
			}
			cout << "\n";
		}
	}


	return 0;
}