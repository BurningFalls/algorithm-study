#include <iostream>
#include <vector>
using namespace std;

// U: 윗 면(w), D: 아랫 면(y), F: 앞 면(r), B: 뒷 면(o), L: 왼쪽 면(g), R: 오른쪽 면(b)
// +: 시계 방향, -: 반시계 방향
// 흰색: w, 노란색: y, 빨간색: r, 오렌지색: o, 초록색: g, 파란색: b

char cube[7][4][4];

void Rotate(char face, char dir) {
	char temp = ' ';
	int wh_face;
	switch (face) {
	case 'U':
		wh_face = 0;
		if (dir == '+') {
			for (int i = 0; i < 3; i++) {
				temp = cube[2][0][i];
				cube[2][0][i] = cube[5][0][i];
				cube[5][0][i] = cube[3][0][i];
				cube[3][0][i] = cube[4][0][i];
				cube[4][0][i] = temp;
			}
		}
		else if (dir == '-') {
			for (int i = 0; i < 3; i++) {
				temp = cube[2][0][i];
				cube[2][0][i] = cube[4][0][i];
				cube[4][0][i] = cube[3][0][i];
				cube[3][0][i] = cube[5][0][i];
				cube[5][0][i] = temp;
			}
		}
		break;
	case 'D':
		wh_face = 1;
		if (dir == '+') {
			for (int i = 0; i < 3; i++) {
				temp = cube[2][2][i];
				cube[2][2][i] = cube[4][2][i];
				cube[4][2][i] = cube[3][2][i];
				cube[3][2][i] = cube[5][2][i];
				cube[5][2][i] = temp;
			}
		}
		else if (dir == '-') {
			for (int i = 0; i < 3; i++) {
				temp = cube[2][2][i];
				cube[2][2][i] = cube[5][2][i];
				cube[5][2][i] = cube[3][2][i];
				cube[3][2][i] = cube[4][2][i];
				cube[4][2][i] = temp;
			}
		}
		break;
	case 'F':
		wh_face = 2;
		if (dir == '+') {
			for (int i = 0; i < 3; i++) {
				temp = cube[0][2][i];
				cube[0][2][i] = cube[4][2 - i][2];
				cube[4][2 - i][2] = cube[1][2][i];
				cube[1][2][i] = cube[5][i][0];
				cube[5][i][0] = temp;
			}
		}
		else if (dir == '-') {
			for (int i = 0; i < 3; i++) {
				temp = cube[0][2][i];
				cube[0][2][i] = cube[5][i][0];
				cube[5][i][0] = cube[1][2][i];
				cube[1][2][i] = cube[4][2 - i][2];
				cube[4][2 - i][2] = temp;
			}
		}
		break;
	case 'B':
		wh_face = 3;
		if (dir == '+') {
			for (int i = 0; i < 3; i++) {
				temp = cube[0][0][2 - i];
				cube[0][0][2 - i] = cube[5][2 - i][2];
				cube[5][2 - i][2] = cube[1][0][2 - i];
				cube[1][0][2 - i] = cube[4][2 - i][0];
				cube[4][2 - i][0] = temp;
			}
		}
		else if (dir == '-') {
			for (int i = 0; i < 3; i++) {
				temp = cube[0][0][2 - i];
				cube[0][0][2 - i] = cube[4][2 - i][0];
				cube[4][2 - i][0] = cube[1][0][2 - i];
				cube[1][0][2 - i] = cube[5][2 - i][2];
				cube[5][2 - i][2] = temp;
			}
		}
		break;
	case 'L':
		wh_face = 4;
		if (dir == '+') {
			for (int i = 0; i < 3; i++) {
				temp = cube[0][i][0];
				cube[0][i][0] = cube[3][2 - i][2];
				cube[3][2 - i][2] = cube[1][2 - i][2];
				cube[1][2 - i][2] = cube[2][i][0];
				cube[2][i][0] = temp;
			}
		}
		else if (dir == '-') {
			for (int i = 0; i < 3; i++) {
				temp = cube[0][i][0];
				cube[0][i][0] = cube[2][i][0];
				cube[2][i][0] = cube[1][2 - i][2];
				cube[1][2 - i][2] = cube[3][2 - i][2];
				cube[3][2 - i][2] = temp;
			}
		}
		break;
	case 'R':
		wh_face = 5;
		if (dir == '+') {
			for (int i = 0; i < 3; i++) {
				temp = cube[0][2 - i][2];
				cube[0][2 - i][2] = cube[2][2 - i][2];
				cube[2][2 - i][2] = cube[1][i][0];
				cube[1][i][0] = cube[3][i][0];
				cube[3][i][0] = temp;
			}
		}
		else if (dir == '-') {
			for (int i = 0; i < 3; i++) {
				temp = cube[0][2 - i][2];
				cube[0][2 - i][2] = cube[3][i][0];
				cube[3][i][0] = cube[1][i][0];
				cube[1][i][0] = cube[2][2 - i][2];
				cube[2][2 - i][2] = temp;
			}
		}
		break;
	}
	if (dir == '+') {
		for (int i = 0; i < 2; i++) {
			temp = cube[wh_face][0][i];
			cube[wh_face][0][i] = cube[wh_face][2 - i][0];
			cube[wh_face][2 - i][0] = cube[wh_face][2][2 - i];
			cube[wh_face][2][2 - i] = cube[wh_face][i][2];
			cube[wh_face][i][2] = temp;
		}
	}
	else if (dir == '-') {
		for (int i = 0; i < 2; i++) {
			temp = cube[wh_face][0][i];
			cube[wh_face][0][i] = cube[wh_face][i][2];
			cube[wh_face][i][2] = cube[wh_face][2][2 - i];
			cube[wh_face][2][2 - i] = cube[wh_face][2 - i][0];
			cube[wh_face][2 - i][0] = temp;
		}
	}
}

int main() {
	int T;
	int N;
	char face = ' ', dir = ' ';
	char color[7] = { 'w', 'y', 'r', 'o', 'g', 'b' };
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cube[i][j][k] = ' ';
			}
		}
	}
	cin >> T;
	for (int a = 0; a < T; a++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					cube[i][j][k] = color[i];
				}
			}
		}
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> face >> dir;
			Rotate(face, dir);
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[0][i][j];
			}
			cout << endl;
		}
	}

	return 0;
}