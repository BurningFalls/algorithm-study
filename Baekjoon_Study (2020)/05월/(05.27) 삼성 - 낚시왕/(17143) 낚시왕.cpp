#include <iostream>
#include <tuple>
using namespace std;

int R, C, M;
tuple<int, int, int> shark[102][102];
tuple<int, int, int> temp_shark[102][102];
// 속력, 이동방향, 크기
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, 1, -1 };
// 1:위, 2:아래, 3:오른쪽, 4:왼쪽
int fishking_pos = 0;
int sharksize_sum = 0;
tuple<int, int, int, int, int> ch_shark;

void Fishing() {
	fishking_pos += 1;
	for (int i = 1; i <= R; i++) {
		if (get<2>(shark[i][fishking_pos])) {
			sharksize_sum += get<2>(shark[i][fishking_pos]);
			shark[i][fishking_pos] = make_tuple(0, 0, 0);
			break;
		}
	}
}

tuple<int, int, int> Move_Shark(int y, int x) {
	int S, D, Z;
	int cal;
	S = get<0>(shark[y][x]);
	D = get<1>(shark[y][x]);
	Z = get<2>(shark[y][x]);

	if (D == 1 || D == 2)
		S %= 2 * (R - 1);
	else if (D == 3 || D == 4)
		S %= 2 * (C - 1);

	while (S) {
		if (D == 1 && y == 1) D = 2;
		else if (D == 2 && y == R) D = 1;
		else if (D == 3 && x == C) D = 4;
		else if (D == 4 && x == 1) D = 3;
		y += dy[D];
		x += dx[D];
		S--;
	}

	return make_tuple(y, x, D);
}

void Move_Sharks() {
	tuple<int, int, int> temp;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			temp_shark[i][j] = make_tuple(0, 0, 0);
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (get<2>(shark[i][j])) {
				temp = Move_Shark(i, j);
				if (get<2>(temp_shark[get<0>(temp)][get<1>(temp)]) < get<2>(shark[i][j]))
					temp_shark[get<0>(temp)][get<1>(temp)] = make_tuple(get<0>(shark[i][j]), get<2>(temp), get<2>(shark[i][j]));
			}
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			shark[i][j] = temp_shark[i][j];
		}
	}
}

int main() {
	int r, c, s, d, z;
	cin >> R >> C >> M;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			shark[i][j] = make_tuple(0, 0, 0);
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		shark[r][c] = make_tuple(s, d, z);
	}

	while (fishking_pos < C) {
		Fishing();
		Move_Sharks();
	}

	cout << sharksize_sum;

	return 0;
}