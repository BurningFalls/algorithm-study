#include <iostream>
using namespace std;

int main() {
	int arr[100][4];
	int cnt = 0;
	for (int num = 2; num <= 100; num++) {
		for (int i = 2; i < num; i++) {
			for (int j = i + 1; j < num; j++) {
				for (int k = j + 1; k < num; k++) {
					if ((num * num * num) == (i * i * i + j * j * j + k * k * k)) {
						arr[cnt][0] = num;
						arr[cnt][1] = i;
						arr[cnt][2] = j;
						arr[cnt][3] = k;
						cnt++;
					}
				}
			}
		}
	}
	for (int i = 0; i < cnt; i++) {
		cout << "Cube = " << arr[i][0] << ", Triple = (" << arr[i][1] << "," << arr[i][2] << "," << arr[i][3] << ")" << endl;
	}

	return 0;
}