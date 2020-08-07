#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[10][2];
	int sum = 0;
	int maximum = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 10; i++) {
		sum += (arr[i][1] - arr[i][0]);
		maximum = max(maximum, sum);
	}
	cout << maximum;

	return 0;
}