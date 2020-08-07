#include <iostream>
#include <math.h>
using namespace std;

int Check(double pos1, double pos2, double pos3, double pos4) {
	double temp1, temp2;
	temp1 = abs(pos2 - pos1) / 2 + abs(pos4 - pos3) / 2;
	temp2 = abs((pos1 + pos2) / 2 - (pos3 + pos4) / 2);
	if (temp1 < temp2)
		return 0; // 만나지 않음
	else if (temp1 == temp2)
		return 1; // 접함
	else if (temp1 > temp2)
		return 2; // 겹침
}


int main() {
	int arr[4][8];
	int flag_row, flag_col;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		flag_row = Check(arr[i][0], arr[i][2], arr[i][4], arr[i][6]);
		flag_col = Check(arr[i][1], arr[i][3], arr[i][5], arr[i][7]);
		if (flag_row == 0 || flag_col == 0)
			cout << "d\n";
		else if (flag_row == 1 && flag_col == 1)
			cout << "c\n";
		else if (flag_row == 1 || flag_col == 1)
			cout << "b\n";
		else
			cout << "a\n";
	}

	return 0;
}