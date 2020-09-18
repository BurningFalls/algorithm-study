#include <iostream>
using namespace std;

int main() {
	int R, C, ZR, ZC;
	char map[52][52];
	char ch_map[252][252];
	cin >> R >> C >> ZR >> ZC;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			for (int y = i * ZR; y < i * ZR + ZR; y++) {
				for (int x = j * ZC; x < j * ZC + ZC; x++) {
					ch_map[y][x] = map[i][j];
				}
			}
		}
	}
	for (int i = 0; i < R * ZR; i++) {
		for (int j = 0; j < C * ZC; j++) {
			cout << ch_map[i][j];
		}
		cout << endl;
	}


	return 0;
}