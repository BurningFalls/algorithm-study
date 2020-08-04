#include <iostream>
using namespace std;

int main() {
	int T;
	int n;
	int arr[41][2];
	cin >> T;
	arr[0][0] = 1; arr[0][1] = 0;
	arr[1][0] = 0; arr[1][1] = 1;
	for (int i = 2; i <= 40; i++) {
		arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
		arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
	}
	for (int a = 0; a < T; a++) {
		cin >> n;
		cout << arr[n][0] << " " << arr[n][1] << endl;
	}

	return 0;
}