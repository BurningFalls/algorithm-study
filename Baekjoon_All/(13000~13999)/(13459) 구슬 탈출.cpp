#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int N, M;	// 보드의 세로, 가로 (3~10)
	// '.' : 빈 칸, '#' : 벽, 'O' : 구멍, 'R' : 빨간 구슬, 'B' : 파란 구슬
queue<tuple<pair<int, int>, pair<int, int>, int>> dir_q;
// first : direction, second : count, third : 이전 방향
char board[11][11];
char basic_board[11][11];
pair<int, int> ch_Rpos, ch_Bpos;

// 성공 : return 1, 실패 : return -1, nothing : return 0
// dir -> 0:왼쪽, 1:오른쪽, 2:위, 3:아래
int Move(pair<int, int>Rp, pair<int, int>Bp, int dir) {
	char sub_board[11];	// 보드판의 한 줄
	int start_node;
	int str_len;
	string str_notO;
	string str_O;
	int NM_max = max(N, M);
	int O_pos;
	int node_R, node_B;
	char sub_board_R[11];
	char sub_board_B[11];

	for (int i = 0; i < 11; i++) {
		sub_board_R[i] = '#';
		sub_board_B[i] = '#';
	}
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			board[i][j] = basic_board[i][j];
		}
	}
	board[Rp.first][Rp.second] = 'R';
	board[Bp.first][Bp.second] = 'B';

	switch (dir) {
	case 0:
		node_R = Rp.second;
		node_B = Bp.second;
		for (int i = 0; i < M; i++) {
			sub_board_R[i] = board[Rp.first][i];
			sub_board_B[i] = board[Bp.first][i];
		}
		break;
	case 1:
		node_R = M - Rp.second - 1;
		node_B = M - Bp.second - 1;
		for (int i = 0; i < M; i++) {
			sub_board_R[i] = board[Rp.first][M - i - 1];
			sub_board_B[i] = board[Bp.first][M - i - 1];
		}
		break;
	case 2:
		node_R = Rp.first;
		node_B = Bp.first;
		for (int i = 0; i < N; i++) {
			sub_board_R[i] = board[i][Rp.second];
			sub_board_B[i] = board[i][Bp.second];
		}
		break;
	case 3:
		node_R = N - Rp.first - 1;
		node_B = N - Bp.first - 1;
		for (int i = 0; i < N; i++) {
			sub_board_R[i] = board[N - i - 1][Rp.second];
			sub_board_B[i] = board[N - i - 1][Bp.second];
		}
		break;
	}

	int left_node = node_R - 1;
	int right_node = node_R + 1;
	while (sub_board_R[left_node] != '#') {
		left_node--;
	}
	while (sub_board_R[right_node] != '#')
		right_node++;
	left_node++;
	right_node--;

	str_notO = "";
	str_O = "";
	for (int i = left_node; i <= right_node; i++) {
		if (sub_board_R[i] == '.') continue;
		if (sub_board_R[i] == 'O') {
			str_O.push_back(sub_board_R[i]);
		}
		else {
			str_notO.push_back(sub_board_R[i]);
			str_O.push_back(sub_board_R[i]);
		}
	}
	if (str_O == "ROB" || str_O == "ORB" || str_O == "OBR")
		return -1;
	else if (str_O == "BOR" || str_O == "OR")
		return 1;
	sub_board_R[node_R] = '.';
	if (str_O.find('B') != string::npos) {
		sub_board_R[node_B] = '.';
	}
	str_len = str_notO.size();
	for (int i = 0; i < str_len; i++) {
		sub_board_R[i + left_node] = str_notO[i];
	}


	left_node = node_B - 1;
	right_node = node_B + 1;
	while (sub_board_B[left_node] != '#') {
		left_node--;
	}
	while (sub_board_B[right_node] != '#')
		right_node++;
	left_node++;
	right_node--;

	str_notO = "";
	str_O = "";
	for (int i = left_node; i <= right_node; i++) {
		if (sub_board_B[i] == '.') continue;
		if (sub_board_B[i] == 'O') {
			str_O.push_back(sub_board_B[i]);
		}
		else {
			str_notO.push_back(sub_board_B[i]);
			str_O.push_back(sub_board_B[i]);
		}
	}
	if (str_O == "ROB" || str_O == "ORB" || str_O == "OBR" || str_O == "OB")
		return -1;
	else if (str_O == "BOR")
		return 1;
	sub_board_B[node_B] = '.';
	if (str_O.find('R') != string::npos) {
		sub_board_B[node_R] = '.';
	}
	str_len = str_notO.size();
	for (int i = 0; i < str_len; i++) {
		sub_board_B[i + left_node] = str_notO[i];
	}

	switch (dir) {
	case 0:
		for (int i = 0; i < M; i++) {
			if (sub_board_R[i] == 'R')
				ch_Rpos = make_pair(Rp.first, i);
			if (sub_board_B[i] == 'B')
				ch_Bpos = make_pair(Bp.first, i);
		}
		break;
	case 1:
		for (int i = 0; i < M; i++) {
			if (sub_board_R[i] == 'R')
				ch_Rpos = make_pair(Rp.first, M - i - 1);
			if (sub_board_B[i] == 'B')
				ch_Bpos = make_pair(Bp.first, M - i - 1);
		}
		break;
	case 2:
		for (int i = 0; i < N; i++) {
			if (sub_board_R[i] == 'R')
				ch_Rpos = make_pair(i, Rp.second);
			if (sub_board_B[i] == 'B')
				ch_Bpos = make_pair(i, Bp.second);
		}
		break;
	case 3:
		for (int i = 0; i < N; i++) {
			if (sub_board_R[i] == 'R')
				ch_Rpos = make_pair(N - i - 1, Rp.second);
			if (sub_board_B[i] == 'B')
				ch_Bpos = make_pair(N - i - 1, Bp.second);
		}
		break;
	}

	return 0;
}

int BFS() {
	pair<int, int> Rpos, Bpos;
	int cnt, x;
	while (!dir_q.empty()) {
		Rpos = make_pair(get<0>(dir_q.front()).first, get<0>(dir_q.front()).second);
		Bpos = make_pair(get<1>(dir_q.front()).first, get<1>(dir_q.front()).second);
		cnt = get<2>(dir_q.front());
		dir_q.pop();
		if (cnt >= 10)
			return 0;
		for (int i = 0; i < 4; i++) {
			x = Move(Rpos, Bpos, i);
			if (x == 1)
				return 1;
			else if (x == -1)
				continue;
			dir_q.push(make_tuple(ch_Rpos, ch_Bpos, cnt + 1));
		}
	}
	return 0;
}

int main() {
	pair<int, int> R, B;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				R = make_pair(i, j);
				basic_board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				B = make_pair(i, j);
				basic_board[i][j] = '.';
			}
			else {
				basic_board[i][j] = board[i][j];
			}
		}
	}
	dir_q.push(make_tuple(R, B, 0));
	cout << BFS();

	return 0;
}