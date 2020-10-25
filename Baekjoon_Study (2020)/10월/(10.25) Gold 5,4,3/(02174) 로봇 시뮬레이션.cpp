#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int A, B;
int visited[101][101] = { 0, };
pair<pair<int, int>, int> robot_inf[101];
pair<int, pair<char, int>> order_inf[101];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
// NESW

// 벽과 충돌하면 return -1
// 다른 로봇과 충돌하면 로봇의 번호 return
// 아무일도 일어나지 않으면 return 0
int Move(int robot, char kind, int repeat) {
	int y = robot_inf[robot].first.first;
	int x = robot_inf[robot].first.second;
	int dir = robot_inf[robot].second;
	if (kind == 'L') {
		FOR(i, 1, repeat % 4)
			dir = (dir + 3) % 4;
	}
	else if (kind == 'R') {
		FOR(i, 1, repeat % 4)
			dir = (dir + 1) % 4;
	}
	else if (kind == 'F') {
		int ny = y, nx = x;
		FOR(i, 1, repeat) {
			ny += dy[dir];
			nx += dx[dir];
			if (ny < 1 || nx < 1 || ny > B || nx > A)
				return -1;
			if (visited[ny][nx])
				return visited[ny][nx];
		}
		visited[y][x] = 0;
		y = ny, x = nx;
		visited[y][x] = robot;
	}
	robot_inf[robot] = { {y, x}, dir };
	return 0;
}

int main() {
	FASTIO;
	int N, M;
	cin >> A >> B;
	cin >> N >> M;
	FOR(i, 1, N) {
		int x, y;
		char dir;
		int temp = -1;
		cin >> x >> y >> dir;
		if (dir == 'N')
			temp = 0;
		else if (dir == 'E')
			temp = 1;
		else if (dir == 'S')
			temp = 2;
		else if (dir == 'W')
			temp = 3;
		robot_inf[i] = { {y, x}, temp };
		visited[y][x] = i;
	}
	FOR(i, 1, M) {
		int robot, repeat;
		char kind;
		cin >> robot >> kind >> repeat;
		order_inf[i] = { robot, {kind, repeat} };
	}

	int flag = 0;
	int robot = 0, repeat;
	char kind;
	FOR(i, 1, M) {
		robot = order_inf[i].first;
		kind = order_inf[i].second.first;
		repeat = order_inf[i].second.second;
		flag = Move(robot, kind, repeat);
		if (flag != 0)
			break;
	}
	if (flag != 0) {
		cout << "Robot ";
		cout << robot;
		cout << " crashes into ";
		if (flag == -1)
			cout << "the wall";
		else
			cout << "robot " << flag;
	}
	else
		cout << "OK";

	return 0;
}