#include <iostream>
#include <queue>
using namespace std;

int dx[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };

struct POS {
	int m_x;
	int m_y;
};

int moveknight(int size, int f_x, int f_y, int l_x, int l_y) {
	int check[300][300] = { 0, };
	queue<POS> q;
	POS cur_node = { f_x, f_y };
	POS next_node;
	q.push(cur_node);
	check[cur_node.m_x][cur_node.m_y] = 1;
	int count = 0;

	while (!q.empty()) {
		cur_node = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			next_node = { cur_node.m_x + dx[i], cur_node.m_y + dy[i] };
			if (next_node.m_x >= 0 && next_node.m_x < size && next_node.m_y >= 0 && next_node.m_y < size) {
				if (check[next_node.m_x][next_node.m_y] == 0) {
					q.push(next_node);
					check[next_node.m_x][next_node.m_y] = check[cur_node.m_x][cur_node.m_y] + 1;
				}
				if (next_node.m_x == l_x && next_node.m_y == l_y) {
					return check[next_node.m_x][next_node.m_y] - 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	int N, I;
	cin >> N;
	POS first_pos;
	POS last_pos;
	int* answer = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> I;
		cin >> first_pos.m_x >> first_pos.m_y;
		cin >> last_pos.m_x >> last_pos.m_y;
		answer[i] = moveknight(I, first_pos.m_x, first_pos.m_y, last_pos.m_x, last_pos.m_y);
	}
	for (int i = 0; i < N; i++) {
		cout << answer[i] << endl;
	}
	return 0;
}