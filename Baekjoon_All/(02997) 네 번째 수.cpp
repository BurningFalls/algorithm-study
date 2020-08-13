#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[4];
	int d1, d2, d;
	for (int i = 0; i <= 2; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 3);
	d1 = arr[1] - arr[0];
	d2 = arr[2] - arr[1];
	d = min(d1, d2);
	if (arr[0] + d != arr[1]) {
		cout << arr[0] + d << endl;
	}
	else if (arr[1] + d != arr[2]) {
		cout << arr[1] + d << endl;
	}
	else {
		cout << arr[2] + d << endl;
	}

	return 0;
}