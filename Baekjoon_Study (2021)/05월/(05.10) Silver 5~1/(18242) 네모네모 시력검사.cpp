#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
char arr[102][102];

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> arr[i][j];
		}
	}
	int sy = 0, sx = 0;
	int ey = 0, ex = 0;
	bool flag = false;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (!flag && arr[i][j] == '#') {
				sy = i;
				sx = j;
				flag = true;
			}
			if (arr[i][j] == '#') {
				ey = i;
				ex = j;
			}
		}
	}
	int len = ey - sy + 1;
	int ans_y = 0, ans_x = 0;
	FOR(i, sy, ey) {
		FOR(j, sx, ex) {
			if (i == sy || i == ey || j == sx || j == ex) {
				if (arr[i][j] == '.') {
					ans_y = i;
					ans_x = j;
				}
			}
		}
	}
	if (ans_y == sy)
		cout << "UP";
	else if (ans_y == ey)
		cout << "DOWN";
	else if (ans_x == sx)
		cout << "LEFT";
	else if (ans_x == ex)
		cout << "RIGHT";


	return 0;
}