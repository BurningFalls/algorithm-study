#include <iostream>
using namespace std;

int main() {
	int arr[5][4];
	int sum[5] = { 0, };
	int temp;
	int maximum;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
			sum[i] += arr[i][j];
		}
	}
	temp = 0;
	maximum = sum[0];
	for (int i = 1; i < 5; i++) {
		if (maximum < sum[i]) {
			maximum = sum[i];
			temp = i;
		}
	}
	cout << temp + 1 << " " << maximum;

	return 0;
}