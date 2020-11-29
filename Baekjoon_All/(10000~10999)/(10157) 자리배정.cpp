#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool arr[1001][1001] = { 0, };
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int main() {
	FASTIO;
	int C, R, K;
	cin >> C >> R;
	cin >> K;
	FOR(i, 0, R + 1) {
		arr[0][i] = 1;
		arr[C + 1][i] = 1;
	}
	FOR(i, 0, C + 1) {
		arr[i][0] = 1;
		arr[i][R + 1] = 1;
	}
	int y = 1;
	int x = 1;
	arr[1][1] = 1;
	int idx = 1;
	int dir = 0;
	bool imp = false;
	int ans_y = 0;
	int ans_x = 0;
	while (true) {
		if (idx == K) {
			ans_y = y;
			ans_x = x;
			break;
		}
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (arr[ny][nx]) {
			if (imp)
				break;
			imp = true;
			dir = (dir + 1) % 4;
		}
		else if (!arr[ny][nx]) {
			imp = false;
			idx++;
			arr[ny][nx] = 1;
			y = ny;
			x = nx;
		}
	}
	if (ans_y == 0 && ans_x == 0)
		cout << 0;
	else
		cout << ans_y << " " << ans_x;

	return 0;
}