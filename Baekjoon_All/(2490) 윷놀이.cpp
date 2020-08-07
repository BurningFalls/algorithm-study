#include <iostream>
using namespace std;

int main() {
	int arr[3][4];
	int sum[3] = { 0, };
	char result[5] = { 'D', 'C', 'B', 'A', 'E' };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
			sum[i] += arr[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << result[sum[i]] << endl;
	}


	return 0;
}