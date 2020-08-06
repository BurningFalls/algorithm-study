#include <iostream>
using namespace std;

int main() {
	int H, W;
	char map[101][101];
	int ans[101][101];
	int cnt;
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cnt = 1;
			if (map[i][j] == 'c') {
				ans[i][j] = 0;
			}
			else if (map[i][j] == '.') {
				for (int k = j - 1; k >= 0; k--) {
					if (map[i][k] != 'c') {
						cnt++;
					}
					else {
						break;
					}
				}
				if (cnt == j + 1) {
					ans[i][j] = -1;
				}
				else {
					ans[i][j] = cnt;
				}
			}
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}