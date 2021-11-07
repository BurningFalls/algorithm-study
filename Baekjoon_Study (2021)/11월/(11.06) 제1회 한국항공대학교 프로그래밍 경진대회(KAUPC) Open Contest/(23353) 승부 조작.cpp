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

int N;
int Map[1002][1002] = { 0, };
int max_score = 0;

int Cur_Score() {
	int maxi = 0;
	FOR(i, 1, N) {
		int cnt = 0;
		bool flag = false;
		FOR(j, 1, N + 1) {
			if (!flag && Map[i][j] == 1) {
				cnt = 1;
				flag = true;
			}
			else if (flag && Map[i][j] == 1) {
				cnt++;
			}
			else if (flag && Map[i][j] != 1) {
				flag = false;
				maxi = max(maxi, cnt);
				cnt = 0;
			}
		}
	}
	FOR(j, 1, N) {
		int cnt = 0;
		bool flag = false;
		FOR(i, 1, N + 1) {
			if (!flag && Map[i][j] == 1) {
				cnt = 1;
				flag = true;
			}
			else if (flag && Map[i][j] == 1) {
				cnt++;
			}
			else if (flag && Map[i][j] != 1) {
				flag = false;
				maxi = max(maxi, cnt);
				cnt = 0;
			}
		}
	}
	for (int diag = 2; diag <= N + 1; diag++) {
		int cnt = 0;
		bool flag = false;
		for (int i = 1; i <= diag; i++) {
			int j = diag - i;
			if (!flag && Map[i][j] == 1) {
				cnt = 1;
				flag = true;
			}
			else if (flag && Map[i][j] == 1) {
				cnt++;
			}
			else if (flag && Map[i][j] != 1) {
				flag = false;
				maxi = max(maxi, cnt);
				cnt = 0;
			}
		}
	}
	for (int diag = N + 2; diag <= 2 * N; diag++) {
		int cnt = 0;
		bool flag = false;
		for (int i = diag - N; i <= N + 1; i++) {
			int j = diag - i;
			if (!flag && Map[i][j] == 1) {
				cnt = 1;
				flag = true;
			}
			else if (flag && Map[i][j] == 1) {
				cnt++;
			}
			else if (flag && Map[i][j] != 1) {
				flag = false;
				maxi = max(maxi, cnt);
				cnt = 0;
			}
		}
	}
	for (int diag = N - 1; diag >= 0; diag--) {
		int cnt = 0;
		bool flag = false;
		for (int i = 1; i <= N - diag + 1; i++) {
			int j = diag + i;
			if (!flag && Map[i][j] == 1) {
				cnt = 1;
				flag = true;
			}
			else if (flag && Map[i][j] == 1) {
				cnt++;
			}
			else if (flag && Map[i][j] != 1) {
				flag = false;
				maxi = max(maxi, cnt);
				cnt = 0;
			}
		}
	}
	for (int diag = 1; diag <= N - 1; diag++) {
		int cnt = 0;
		bool flag = false;
		for (int i = diag + 1; i <= N + 1; i++) {
			int j = diag + i;
			if (!flag && Map[i][j] == 1) {
				cnt = 1;
				flag = true;
			}
			else if (flag && Map[i][j] == 1) {
				cnt++;
			}
			else if (flag && Map[i][j] != 1) {
				flag = false;
				maxi = max(maxi, cnt);
				cnt = 0;
			}
		}
	}
	return maxi;
}

int Scoring(int sy, int sx) {
	int maxi = 0;
	int lefty = sy, righty = sy;
	int leftx = sx, rightx = sx;
	while (lefty >= 1 && Map[lefty][sx] == 1) {
		lefty--;
	}
	while (righty <= N && Map[righty][sx] == 1) {
		righty++;
	}
	while (leftx >= 1 && Map[sy][leftx] == 1) {
		leftx--;
	}
	while (rightx <= N && Map[sy][rightx] == 1) {
		rightx++;
	}
	maxi = max(maxi, righty - lefty - 1);
	maxi = max(maxi, rightx - leftx - 1);
	int y1 = sy, x1 = sx;
	int y2 = sy, x2 = sx;
	while (y1 <= N && x1 <= N && Map[y1][x1] == 1) {
		y1++;
		x1++;
	}
	while (y2 >= 1 && x2 >= 1 && Map[y2][x2] == 1) {
		y2--;
		x2--;
	}
	maxi = max(maxi, y1 - y2 - 1);
	y1 = sy, x1 = sx;
	y2 = sy, x2 = sx;
	while (y1 >= 1 && x1 <= N && Map[y1][x1] == 1) {
		y1--;
		x1++;
	}
	while (y2 <= N && x2 >= 1 && Map[y2][x2] == 1) {
		y2++;
		x2--;
	}
	maxi = max(maxi, x1 - x2 - 1);
	return maxi;
}

int main() {
	FASTIO;
	int ans = 0;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
		}
	}
	ans = max(ans, Cur_Score());
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (Map[i][j] != 2) continue;
			Map[i][j] = 1;
			ans = max(ans, Scoring(i, j));
			Map[i][j] = 2;
		}
	}
	cout << ans;

	return 0;
}