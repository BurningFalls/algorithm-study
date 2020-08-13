#include <iostream>
#include <algorithm>
using namespace std;

int N;
int qy[11][5][5];
char clr[11][5][5];
int map_qy[6][6];
char map_clr[6][6];
bool visited[11] = { 0, };
int order[3];
int way[3];
int maximum = -987654321;

void Change() {
	for (int x = 0; x < 3; x++) {
		switch (way[x]) {
		case 0:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map_qy[i][j] += qy[order[x]][i][j];
					if (map_qy[i][j] < 0)
						map_qy[i][j] = 0;
					else if (map_qy[i][j] > 9)
						map_qy[i][j] = 9;
					if (clr[order[x]][i][j] != 'W')
						map_clr[i][j] = clr[order[x]][i][j];
				}
			}
			break;
		case 1:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map_qy[i][j + 1] += qy[order[x]][i][j];
					if (map_qy[i][j + 1] < 0)
						map_qy[i][j + 1] = 0;
					else if (map_qy[i][j + 1] > 9)
						map_qy[i][j + 1] = 9;
					if (clr[order[x]][i][j] != 'W')
						map_clr[i][j + 1] = clr[order[x]][i][j];
				}
			}
			break;
		case 2:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map_qy[i + 1][j] += qy[order[x]][i][j];
					if (map_qy[i + 1][j] < 0)
						map_qy[i + 1][j] = 0;
					else if (map_qy[i + 1][j] > 9)
						map_qy[i + 1][j] = 9;
					if (clr[order[x]][i][j] != 'W')
						map_clr[i + 1][j] = clr[order[x]][i][j];
				}
			}
			break;
		case 3:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map_qy[i + 1][j + 1] += qy[order[x]][i][j];
					if (map_qy[i + 1][j + 1] < 0)
						map_qy[i + 1][j + 1] = 0;
					else if (map_qy[i + 1][j + 1] > 9)
						map_qy[i + 1][j + 1] = 9;
					if (clr[order[x]][i][j] != 'W')
						map_clr[i + 1][j + 1] = clr[order[x]][i][j];
				}
			}
			break;
		case 4:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map_qy[i][j] += qy[order[x]][4 - j - 1][i];
					if (map_qy[i][j] < 0)
						map_qy[i][j] = 0;
					else if (map_qy[i][j] > 9)
						map_qy[i][j] = 9;
					if (clr[order[x]][4 - j - 1][i] != 'W')
						map_clr[i][j] = clr[order[x]][4 - j - 1][i];
				}
			}
			break;
		case 5:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map_qy[i][j + 1] += qy[order[x]][4 - j - 1][i];
					if (map_qy[i][j + 1] < 0)
						map_qy[i][j + 1] = 0;
					else if (map_qy[i][j + 1] > 9)
						map_qy[i][j + 1] = 9;
					if (clr[order[x]][4 - j - 1][i] != 'W')
						map_clr[i][j + 1] = clr[order[x]][4 - j - 1][i];
				}
			}
			break;
		case 6:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map_qy[i + 1][j] += qy[order[x]][4 - j - 1][i];
					if (map_qy[i + 1][j] < 0)
						map_qy[i + 1][j] = 0;
					else if (map_qy[i + 1][j] > 9)
						map_qy[i + 1][j] = 9;
					if (clr[order[x]][4 - j - 1][i] != 'W')
						map_clr[i + 1][j] = clr[order[x]][4 - j - 1][i];
				}
			}
			break;
		case 7:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map_qy[i + 1][j + 1] += qy[order[x]][4 - j - 1][i];
					if (map_qy[i + 1][j + 1] < 0)
						map_qy[i + 1][j + 1] = 0;
					else if (map_qy[i + 1][j + 1] > 9)
						map_qy[i + 1][j + 1] = 9;
					if (clr[order[x]][4 - j - 1][i] != 'W')
						map_clr[i + 1][j + 1] = clr[order[x]][4 - j - 1][i];
				}
			}
			break;
		case 8:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map_qy[i][j] += qy[order[x]][4 - i - 1][4 - j - 1];
					if (map_qy[i][j] < 0)
						map_qy[i][j] = 0;
					else if (map_qy[i][j] > 9)
						map_qy[i][j] = 9;
					if (clr[order[x]][4 - i - 1][4 - j - 1] != 'W')
						map_clr[i][j] = clr[order[x]][4 - i - 1][4 - j - 1];
				}
			}
			break;
		case 9:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map_qy[i][j + 1] += qy[order[x]][4 - i - 1][4 - j - 1];
					if (map_qy[i][j + 1] < 0)
						map_qy[i][j + 1] = 0;
					else if (map_qy[i][j + 1] > 9)
						map_qy[i][j + 1] = 9;
					if (clr[order[x]][4 - i - 1][4 - j - 1] != 'W')
						map_clr[i][j + 1] = clr[order[x]][4 - i - 1][4 - j - 1];
				}
			}
			break;
		case 10:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map_qy[i + 1][j] += qy[order[x]][4 - i - 1][4 - j - 1];
					if (map_qy[i + 1][j] < 0)
						map_qy[i + 1][j] = 0;
					else if (map_qy[i + 1][j] > 9)
						map_qy[i + 1][j] = 9;
					if (clr[order[x]][4 - i - 1][4 - j - 1] != 'W')
						map_clr[i + 1][j] = clr[order[x]][4 - i - 1][4 - j - 1];
				}
			}
			break;
		case 11:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map_qy[i + 1][j + 1] += qy[order[x]][4 - i - 1][4 - j - 1];
					if (map_qy[i + 1][j + 1] < 0)
						map_qy[i + 1][j + 1] = 0;
					else if (map_qy[i + 1][j + 1] > 9)
						map_qy[i + 1][j + 1] = 9;
					if (clr[order[x]][4 - i - 1][4 - j - 1] != 'W')
						map_clr[i + 1][j + 1] = clr[order[x]][4 - i - 1][4 - j - 1];
				}
			}
			break;
		case 12:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map_qy[i][j] += qy[order[x]][j][4 - i - 1];
					if (map_qy[i][j] < 0)
						map_qy[i][j] = 0;
					else if (map_qy[i][j] > 9)
						map_qy[i][j] = 9;
					if (clr[order[x]][j][4 - i - 1] != 'W')
						map_clr[i][j] = clr[order[x]][j][4 - i - 1];
				}
			}
			break;
		case 13:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map_qy[i][j + 1] += qy[order[x]][j][4 - i - 1];
					if (map_qy[i][j + 1] < 0)
						map_qy[i][j + 1] = 0;
					else if (map_qy[i][j + 1] > 9)
						map_qy[i][j + 1] = 9;
					if (clr[order[x]][j][4 - i - 1] != 'W')
						map_clr[i][j + 1] = clr[order[x]][j][4 - i - 1];
				}
			}
			break;
		case 14:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map_qy[i + 1][j] += qy[order[x]][j][4 - i - 1];
					if (map_qy[i + 1][j] < 0)
						map_qy[i + 1][j] = 0;
					else if (map_qy[i + 1][j] > 9)
						map_qy[i + 1][j] = 9;
					if (clr[order[x]][j][4 - i - 1] != 'W')
						map_clr[i + 1][j] = clr[order[x]][j][4 - i - 1];
				}
			}
			break;
		case 15:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map_qy[i + 1][j + 1] += qy[order[x]][j][4 - i - 1];
					if (map_qy[i + 1][j + 1] < 0)
						map_qy[i + 1][j + 1] = 0;
					else if (map_qy[i + 1][j + 1] > 9)
						map_qy[i + 1][j + 1] = 9;
					if (clr[order[x]][j][4 - i - 1] != 'W')
						map_clr[i + 1][j + 1] = clr[order[x]][j][4 - i - 1];
				}
			}
			break;
		}
	}
}

int Calculate() {
	int R = 0, B = 0, G = 0, Y = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (map_clr[i][j] == 'R')
				R += map_qy[i][j];
			else if (map_clr[i][j] == 'B')
				B += map_qy[i][j];
			else if (map_clr[i][j] == 'G')
				G += map_qy[i][j];
			else if (map_clr[i][j] == 'Y')
				Y += map_qy[i][j];
		}
	}
	return (7 * R + 5 * B + 3 * G + 2 * Y);
}

void Choose_Way(int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				map_qy[i][j] = 0;
				map_clr[i][j] = 'W';
			}
		}
		Change();
		maximum = max(maximum, Calculate());
		return;
	}
	for (int i = 0; i < 16; i++) {
		way[cnt] = i;
		Choose_Way(cnt + 1);
	}
}

void Choose_Order(int cnt) {
	if (cnt == 3) {
		Choose_Way(0);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		order[cnt] = i;
		Choose_Order(cnt + 1);
		visited[i] = 0;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> qy[i][j][k];
			}
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> clr[i][j][k];
			}
		}
	}
	Choose_Order(0);
	cout << maximum;

	return 0;
}