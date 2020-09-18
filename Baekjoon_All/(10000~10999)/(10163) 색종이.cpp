#include <iostream>
using namespace std;

int main() {
	int N;
	int map[101][101] = { 0, };
	int cnt[101] = { 0, };
	int row, col, width, height;
	cin >> N;
	for (int num = 1; num <= N; num++) {
		cin >> row >> col >> width >> height;
		for (int i = col; i < col + height; i++) {
			for (int j = row; j < row + width; j++) {
				map[i][j] = num;
			}
		}
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (map[i][j] == 0) continue;
			cnt[map[i][j]]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << cnt[i] << "\n";
	}

	return 0;
}