#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;	// 보드의 크기 (1~20)
int board[21][21];
int ori_board[21][21];
queue<int> q;
queue<int> ch_q;
int direction[5];	// 1:왼쪽, 2:오른쪽, 3:위, 4:아래
int maximum_block = 0;

void Copy_Board() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = ori_board[i][j];
		}
	}
}

void Move(int dir) {
	int num1, num2;
	int ch_q_len;
	for (int i = 0; i < N; i++) {
		switch (dir) {
		case 1: // 왼쪽
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 0) continue;
				q.push(board[i][j]);
			}
			break;
		case 2: // 오른쪽
			for (int j = N - 1; j >= 0; j--) {
				if (board[i][j] == 0) continue;
				q.push(board[i][j]);
			}
			break;
		case 3: // 위
			for (int j = 0; j < N; j++) {
				if (board[j][i] == 0) continue;
				q.push(board[j][i]);
			}
			break;
		case 4:	// 아래
			for (int j = N - 1; j >= 0; j--) {
				if (board[j][i] == 0) continue;
				q.push(board[j][i]);
			}
			break;
		}

		while (!q.empty()) {
			if (q.size() == 1) {
				ch_q.push(q.front());
				q.pop();
				break;
			}
			num1 = q.front();
			q.pop();
			num2 = q.front();
			if (num1 == num2) {
				ch_q.push(num1 * 2);
				q.pop();
			}
			else if (num1 != num2) {
				ch_q.push(num1);
			}
		}
		ch_q_len = ch_q.size();
		for (int j = 0; j < N - ch_q_len; j++) {
			ch_q.push(0);
		}

		switch (dir) {
		case 1: // 왼쪽
			for (int j = 0; j < N; j++) {
				board[i][j] = ch_q.front();
				ch_q.pop();
			}
			break;
		case 2: // 오른쪽
			for (int j = N - 1; j >= 0; j--) {
				board[i][j] = ch_q.front();
				ch_q.pop();
			}
			break;
		case 3: // 위
			for (int j = 0; j < N; j++) {
				board[j][i] = ch_q.front();
				ch_q.pop();
			}
			break;
		case 4:	// 아래
			for (int j = N - 1; j >= 0; j--) {
				board[j][i] = ch_q.front();
				ch_q.pop();
			}
			break;
		}
	}
}


void Choose_Dir(int cnt) {
	if (cnt == 5) {
		Copy_Board();
		for (int i = 0; i < 5; i++) {
			Move(direction[i]);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				maximum_block = max(maximum_block, board[i][j]);
			}
		}
		return;
	}

	for (int i = 1; i <= 4; i++) {
		direction[cnt] = i;
		Choose_Dir(cnt + 1);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ori_board[i][j];
		}
	}

	Choose_Dir(0);

	cout << maximum_block;

	return 0;
}