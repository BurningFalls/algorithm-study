#include <iostream>
using namespace std;

int main() {
	int N, R, C;
	char map[100][100];
	cin >> N >> R >> C;
	if ((R + C) % 2 == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if ((i + j) % 2 == 0)
					map[i][j] = '.';
				else
					map[i][j] = 'v';
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if ((i + j) % 2 == 0)
					map[i][j] = 'v';
				else
					map[i][j] = '.';
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}


	return 0;
}