#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	char arr[6][3];
	// R, B, Y, G
	char cnt[4] = { 0, 0, 0, 0 };
	int num_cnt[10] = { 0, };
	int sum = 0;
	int temp;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
			if (j == 0) {
				if (arr[i][0] == 'R')
					cnt[0]++;
				else if (arr[i][0] == 'B')
					cnt[1]++;
				else if (arr[i][0] == 'Y')
					cnt[2]++;
				else if (arr[i][0] == 'G')
					cnt[3]++;
			}
			else if (j == 1) {
				num_cnt[arr[i][j] - '1' + 1]++;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		// 1 & 4
		if (cnt[i] == 5) {
			// 1
			for (int j = 1; j <= 5; j++) {
				if (num_cnt[j] == 1 && num_cnt[j + 1] == 1 && num_cnt[j + 2] == 1 && num_cnt[j + 3] == 1 && num_cnt[j + 4] == 1) {
					temp = j + 4 + 900;
					sum = max(sum, temp);
					temp = 0;
				}
			}
			// 4
			for (int j = 9; j >= 1; j--) {
				if (num_cnt[j] != 0) {
					temp = j;
					break;
				}
			}
			temp += 600;
			sum = max(sum, temp);
			temp = 0;
		}
	}
	// 2
	for (int i = 1; i <= 9; i++) {
		if (num_cnt[i] == 4) {
			temp = i + 800;
			sum = max(sum, temp);
			temp = 0;
		}
	}
	// 3
	for (int i = 1; i <= 9; i++) {
		if (num_cnt[i] == 3) {
			for (int j = i + 1; j <= 9; j++) {
				if (num_cnt[j] == 2) {
					temp = i * 10 + j + 700;
					sum = max(sum, temp);
					temp = 0;
				}
			}
			// 6
			temp = i + 400;
			sum = max(sum, temp);
			temp = 0;
		}
		else if (num_cnt[i] == 2) {
			for (int j = i + 1; j <= 9; j++) {
				if (num_cnt[j] == 3) {
					temp = j * 10 + i + 700;
					sum = max(sum, temp);
					temp = 0;
				}
			}
		}
	}
	// 5
	for (int i = 1; i <= 5; i++) {
		if (num_cnt[i] == 1 && num_cnt[i + 1] == 1 && num_cnt[i + 2] == 1 && num_cnt[i + 3] == 1 && num_cnt[i + 4] == 1) {
			temp = i + 4 + 500;
			sum = max(sum, temp);
			temp = 0;
		}
	}
	// 7
	for (int i = 1; i <= 9; i++) {
		if (num_cnt[i] == 2) {
			for (int j = i + 1; j <= 9; j++) {
				if (num_cnt[j] == 2) {
					temp = max(i, j) * 10 + min(i, j) + 300;
					sum = max(sum, temp);
					temp = 0;
				}
			}
			// 8
			temp = i + 200;
			sum = max(sum, temp);
			temp = 0;
		}
	}
	// 9
	for (int i = 9; i >= 1; i--) {
		if (num_cnt[i] != 0) {
			temp = i + 100;
			sum = max(sum, temp);
			temp = 0;
			break;
		}
	}
	cout << sum;

	return 0;
}