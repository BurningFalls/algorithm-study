#include <iostream>
using namespace std;

int main() {
	int R, C;
	char map[51][51];
	char card[101][101];
	int A, B;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	cin >> A >> B;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			card[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			card[i][j + C] = map[i][C - j - 1];
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < 2 * C; j++) {
			card[i + R][j] = card[R - i - 1][j];
		}
	}

	if (card[A - 1][B - 1] == '#') {
		card[A - 1][B - 1] = '.';
	}
	else if (card[A - 1][B - 1] == '.') {
		card[A - 1][B - 1] = '#';
	}

	for (int i = 0; i < 2 * R; i++) {
		for (int j = 0; j < 2 * C; j++) {
			cout << card[i][j];
		}
		cout << endl;
	}

	return 0;
}