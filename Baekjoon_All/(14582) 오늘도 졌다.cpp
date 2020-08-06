#include <iostream>
using namespace std;

int main() {
	int arr[2][10];
	bool flag = false;
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 2; j++) {
			if (j == 0)
				sum1 += arr[0][i];
			else if (j == 1)
				sum2 += arr[1][i];
			if (sum1 > sum2)
				flag = true;
		}
	}
	if (flag)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}