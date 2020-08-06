#include <iostream>
using namespace std;

int main() {
	char map[9][9];
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)) {
				if (map[i][j] == 'F') {
					cnt++;
				}
			}
		}
	}
	cout << cnt;

	return 0;
}