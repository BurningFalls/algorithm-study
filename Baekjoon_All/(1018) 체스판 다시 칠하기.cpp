#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
char map[51][51];
char chess_map1[9][9];
char chess_map2[9][9];
int minimum = 65;
int wrong1;
int wrong2;

int Check1(int y, int x) {
	wrong1 = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess_map1[i][j] != map[y + i][x + j]) {
				wrong1++;
				if (minimum <= wrong1) {
					return 65;
				}
			}
		}
	}
	return wrong1;
}

int Check2(int y, int x) {
	wrong2 = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess_map2[i][j] != map[y + i][x + j]) {
				wrong2++;
				if (minimum <= wrong2) {
					return 65;
				}
			}
		}
	}
	return wrong2;
}

int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				chess_map1[i][j] = 'W';
				chess_map2[i][j] = 'B';
			}
			else if ((i + j) % 2 == 1) {
				chess_map1[i][j] = 'B';
				chess_map2[i][j] = 'W';
			}
		}
	}

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			minimum = min({ minimum, Check1(i, j), Check2(i, j) });
		}
	}
	cout << minimum;

	return 0;
}