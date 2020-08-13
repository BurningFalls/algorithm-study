#include <iostream>
#include <cstring>
using namespace std;

int N, H, W;
int map[501][501];
int R[10];
int M;
int m_arr[62501][4];
int K;
bool visited[501][501] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int Kind[501][501];
bool flag;

bool Enemy_Check(int y, int x, int kind) {
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
		if (Kind[ny][nx] == !kind) {
			return true;
		}
	}
	return false;
}

void DFS(int y, int x, int a, int b, int kind, int sta) {
	if (y == a && x == b) {
		flag = true;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
		if (map[ny][nx] == -1) continue;
		if (visited[ny][nx]) continue;
		if (Kind[ny][nx] == !kind) continue;
		if (sta - map[ny][nx] < 0) continue;
		if (!(ny == a && nx == b)) {
			if (Enemy_Check(ny, nx, kind)) continue;
		}
		visited[ny][nx] = 1;
		DFS(ny, nx, a, b, kind, sta - map[ny][nx]);
		if (flag == true)
			return;
		visited[ny][nx] = 0;
	}
}

void Move(int u, int a, int b) {
	int move_ability = m_arr[u][0];
	int kind = m_arr[u][1];
	int cur_y = m_arr[u][2];
	int cur_x = m_arr[u][3];
	flag = false;

	if (Kind[a][b] != -1 || map[a][b] == -1)
		return;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			visited[i][j] = 0;
		}
	}

	visited[cur_y][cur_x] = 1;
	DFS(cur_y, cur_x, a, b, kind, move_ability);
	if (flag) {
		m_arr[u][2] = a;
		m_arr[u][3] = b;
		Kind[cur_y][cur_x] = -1;
		Kind[a][b] = kind;
	}
}

int main() {
	int m, t, a, b, u;
	memset(Kind, -1, sizeof(Kind));
	cin >> N >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= N; i++)
		cin >> R[i];
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			map[i][j] = R[map[i][j]];
		}
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> m_arr[i][j];
		}
		Kind[m_arr[i][2]][m_arr[i][3]] = m_arr[i][1];
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> u >> a >> b;
		Move(u, a, b);
	}
	for (int i = 1; i <= M; i++) {
		cout << m_arr[i][2] << " " << m_arr[i][3] << "\n";
	}

	return 0;
}