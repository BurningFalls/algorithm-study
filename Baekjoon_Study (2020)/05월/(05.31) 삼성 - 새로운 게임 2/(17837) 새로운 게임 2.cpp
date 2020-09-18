#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, K;
int board_color[13][13];
// 0: 흰색, 1: 빨간색, 2: 파란색
vector<tuple<int, int, int>> chess_inf;
vector<pair<int, int>> chess_board[13][13];
// first: 번호, second: 방향 (1:오른쪽/2:왼쪽,3:위쪽,4:아래쪽)
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

bool Do_White_or_Red(int color, int node, int y, int x, int d) {
	int ny, nx;
	int loc = 0;
	int len, len_new;
	ny = y + dy[d];
	nx = x + dx[d];
	len = chess_board[y][x].size();
	for (int i = 0; i < len; i++) {
		if (chess_board[y][x][i].first == node) {
			loc = i;
			break;
		}
	}
	len_new = chess_board[ny][nx].size();
	if (color == 1) {
		for (int i = loc; i < len; i++) {
			chess_inf[chess_board[y][x][i].first] = make_tuple(ny, nx, chess_board[y][x][i].second);
		}
		for (int i = 0; i < len - loc; i++) {
			chess_board[ny][nx].push_back(chess_board[y][x].back());
			len_new += 1;
			if (len_new >= 4)
				return false;
			chess_board[y][x].pop_back();
		}
	}
	else if (color == 0) {
		for (int i = loc; i < len; i++) {
			chess_board[ny][nx].push_back(chess_board[y][x][i]);
			len_new += 1;
			if (len_new >= 4)
				return false;
			chess_inf[chess_board[y][x][i].first] = make_tuple(ny, nx, chess_board[y][x][i].second);
		}
		for (int i = 0; i < len - loc; i++) {
			chess_board[y][x].pop_back();
		}
	}
	return true;
}

bool Do_Blue(int node, int y, int x, int d) {
	int ny, nx;
	int len;
	bool flag = true;
	if (d == 1) d = 2;
	else if (d == 2) d = 1;
	else if (d == 3) d = 4;
	else if (d == 4) d = 3;
	get<2>(chess_inf[node]) = d;
	len = chess_board[y][x].size();
	for (int i = 0; i < len; i++) {
		if (chess_board[y][x][i].first == node)
			chess_board[y][x][i].second = d;
	}
	ny = y + dy[d];
	nx = x + dx[d];
	if (ny < 0 || nx < 0 || ny >= N || nx >= N) return true;
	else if (board_color[ny][nx] == 2) return true;
	else if (board_color[ny][nx] == 1) flag = Do_White_or_Red(1, node, y, x, d);
	else if (board_color[ny][nx] == 0) flag = Do_White_or_Red(0, node, y, x, d);

	return flag;
}

bool Move_Chess() {
	int pos_y, pos_x, dir;
	int npos_y, npos_x;
	int len;
	bool flag = true;
	for (int i = 0; i < K; i++) {
		pos_y = get<0>(chess_inf[i]);
		pos_x = get<1>(chess_inf[i]);
		dir = get<2>(chess_inf[i]);
		npos_y = pos_y + dy[dir];
		npos_x = pos_x + dx[dir];
		if (npos_y < 0 || npos_x < 0 || npos_y >= N || npos_x >= N) flag = Do_Blue(i, pos_y, pos_x, dir);
		else if (board_color[npos_y][npos_x] == 2) flag = Do_Blue(i, pos_y, pos_x, dir);
		else if (board_color[npos_y][npos_x] == 1) flag = Do_White_or_Red(1, i, pos_y, pos_x, dir);
		else if (board_color[npos_y][npos_x] == 0) flag = Do_White_or_Red(0, i, pos_y, pos_x, dir);
		if (!flag)
			return flag;
	}
	return true;
}

int main() {
	int col, row, dir;
	int turn = 1;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board_color[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> col >> row >> dir;
		chess_board[col - 1][row - 1].push_back(make_pair(i, dir));
		chess_inf.push_back(make_tuple(col - 1, row - 1, dir));
	}

	while (turn <= 1000 && Move_Chess())
		turn += 1;

	if (turn == 1001)
		cout << -1;
	else
		cout << turn;

	return 0;
}