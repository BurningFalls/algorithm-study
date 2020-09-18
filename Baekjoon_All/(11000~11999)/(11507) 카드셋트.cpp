#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	bool arr[4][14] = { 0, };
	char shapes[5] = { 'P', 'K', 'H', 'T' };
	char shape;
	int num;
	bool flag = false;
	int cnt;
	cin >> str;
	for (int i = 0; i < str.size(); i += 3) {
		shape = str[i];
		num = (int(str[i + 1]) - '0') * 10 + (int(str[i + 2]) - '0');
		for (int j = 0; j < 4; j++) {
			if (shape == shapes[j]) {
				if (arr[j][num] == 1) {
					flag = true;
					break;
				}
				else {
					arr[j][num] = 1;
					break;
				}
			}
		}
		if (flag)
			break;
	}
	if (flag)
		cout << "GRESKA";
	else {
		for (int i = 0; i < 4; i++) {
			cnt = 0;
			for (int j = 1; j <= 13; j++) {
				if (arr[i][j] == 0) {
					cnt++;
				}
			}
			cout << cnt << " ";
		}
	}

	return 0;
}