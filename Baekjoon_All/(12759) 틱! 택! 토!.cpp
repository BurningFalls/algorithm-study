#include <iostream>
using namespace std;

int arr[3][3] = { 0, };

int Check() {
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < 3; i++) {
		cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] == 1)
				cnt1++;
			else if (arr[i][j] == 2)
				cnt2++;
		}
		if (cnt1 == 3)
			return 1;
		else if (cnt2 == 3)
			return 2;
	}
	for (int i = 0; i < 3; i++) {
		cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < 3; j++) {
			if (arr[j][i] == 1)
				cnt1++;
			else if (arr[j][i] == 2)
				cnt2++;
		}
		if (cnt1 == 3)
			return 1;
		else if (cnt2 == 3)
			return 2;
	}

	cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < 3; i++) {
		if (arr[i][i] == 1)
			cnt1++;
		else if (arr[i][i] == 2)
			cnt2++;
	}
	if (cnt1 == 3)
		return 1;
	else if (cnt2 == 3)
		return 2;
	cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < 3; i++) {
		if (arr[i][2 - i] == 1)
			cnt1++;
		else if (arr[i][2 - i] == 2)
			cnt2++;
	}
	if (cnt1 == 3)
		return 1;
	else if (cnt2 == 3)
		return 2;

	return 0;
}

int main() {
	int start_player;
	int x, y;
	bool flag = false;

	cin >> start_player;
	for (int i = 0; i < 9; i++) {
		cin >> x >> y;
		arr[x - 1][y - 1] = i % 2 + 1;
		if (Check() == 1) {
			if (start_player == 1)
				cout << 1;
			else if (start_player == 2)
				cout << 2;
			flag = true;
			break;
		}
		else if (Check() == 2) {
			if (start_player == 1)
				cout << 2;
			else if (start_player == 2)
				cout << 1;
			flag = true;
			break;
		}
	}
	if (flag == false)
		cout << 0;

	return 0;
}