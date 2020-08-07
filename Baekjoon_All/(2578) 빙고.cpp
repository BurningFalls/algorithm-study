#include <iostream>
using namespace std;

bool check[5][5] = { 0, };

bool Check() {
	int bingo = 0;
	int cnt;
	for (int i = 0; i < 5; i++) {
		cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (check[i][j] == 1)
				cnt++;
		}
		if (cnt == 5)
			bingo++;
	}
	for (int i = 0; i < 5; i++) {
		cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (check[j][i] == 1)
				cnt++;
		}
		if (cnt == 5)
			bingo++;
	}
	cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (check[i][i] == 1)
			cnt++;
	}
	if (cnt == 5)
		bingo++;
	cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (check[5 - i - 1][i] == 1)
			cnt++;
	}
	if (cnt == 5)
		bingo++;
	if (bingo >= 3)
		return true;
	else
		return false;
}

int main() {
	int map[5][5];
	int num[26];
	int turn = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= 25; i++) {
		cin >> num[i];
	}

	while (!Check()) {
		turn++;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (map[i][j] == num[turn]) {
					check[i][j] = 1;
					break;
				}
			}
		}
	}
	cout << turn;

	return 0;
}