#include <iostream>
using namespace std;

int main() {
	int T;
	int n;
	int arr[11];
	cin >> T;
	arr[1] = 1;		// 1
	arr[2] = 2;		// 1+1, 2
	arr[3] = 4;		// 1+2, 1+1+1, 2+1, 3
	for (int i = 4; i <= 10; i++) {
		arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
	}
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << arr[n] << endl;
	}

	return 0;
}