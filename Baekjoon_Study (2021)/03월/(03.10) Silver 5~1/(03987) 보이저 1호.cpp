#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int
#define INF 987654321

int N, M;
char Map[502][502];
int pr, pc;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int Dir;
int visited[502][502];
char direct[4] = { 'U', 'R', 'D', 'L' };

int Travel(int dir) {
	int y = pr, x = pc;
	int Time = 1;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			visited[i][j] = 5;
		}
	}
	visited[y][x] = dir;
	while (true) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 1 || nx < 1 || ny > N || nx > M)
			break;
		if (Map[ny][nx] == 'C')
			break;
		if (visited[ny][nx] == dir) {
			Time = INF;
			break;
		}
		if (Map[ny][nx] == '/') {
			if (dir == 0 || dir == 2)
				dir = (dir + 1) % 4;
			else if (dir == 1 || dir == 3)
				dir = (dir + 3) % 4;
		}
		else if (Map[ny][nx] == '\\') {
			if (dir == 0 || dir == 2)
				dir = (dir + 3) % 4;
			else if (dir == 1 || dir == 3)
				dir = (dir + 1) % 4;
		}
		visited[ny][nx] = dir;
		y = ny, x = nx;
		Time++;
	}
 	return Time;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	cin >> pr >> pc;
	int maximum = 0;
	char ans;
	FOR(i, 0, 3) {
		int tmp = Travel(i);
		if (maximum < tmp) {
			ans = direct[i];
			maximum = tmp;
		}
	}
	cout << ans << "\n";
	if (maximum == INF)
		cout << "Voyager";
	else {
		cout << maximum;
	}

	return 0;
}