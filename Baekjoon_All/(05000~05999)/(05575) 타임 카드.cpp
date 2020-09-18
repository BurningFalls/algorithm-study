#include <iostream>
using namespace std;

int main() {
	int arr[3][6];
	int dif;
	int h, m, s;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		dif = (arr[i][3] * 3600 + arr[i][4] * 60 + arr[i][5]) - (arr[i][0] * 3600 + arr[i][1] * 60 + arr[i][2]);
		h = dif / 3600;
		dif -= h * 3600;
		m = dif / 60;
		dif -= m * 60;
		s = dif;
		cout << h << " " << m << " " << s << endl;
	}

	return 0;
}