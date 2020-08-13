#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

bool check[8889] = { 0, }; // 0 -> 1111, 8888 -> 9999
int card_num[4];

void DFS(int cnt) {
	if (cnt == 4) {
		int minimum = 10000;
		int temp;
		for (int i = 0; i <= 3; i++) {
			temp = 0;
			for (int j = i; j <= i + 3; j++) {
				temp += card_num[j % 4] * pow(10, 3 - (j - i));
			}
			minimum = min(minimum, temp);
		}
		check[minimum - 1111] = 1;

		return;
	}

	for (int i = 1; i <= 9; i++) {
		card_num[cnt] = i;
		DFS(cnt + 1);
	}
}


int main() {
	DFS(0);
	int arr[4];
	int minimum = 10000;
	int temp;
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i <= 3; i++) {
		temp = 0;
		for (int j = i; j <= i + 3; j++) {
			temp += arr[j % 4] * pow(10, 3 - (j - i));
		}
		minimum = min(minimum, temp);
	}
	check[minimum - 1111] = 1;

	for (int i = 0; i <= minimum - 1111; i++) {
		if (check[i])
			cnt++;
	}

	cout << cnt;

	return 0;
}