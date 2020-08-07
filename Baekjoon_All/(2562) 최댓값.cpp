#include <iostream>
using namespace std;

int main() {
	int arr[9];
	int max;
	int n = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	max = arr[0];
	for (int i = 1; i < 9; i++) {
		if (max < arr[i]) {
			max = arr[i];
			n = i;
		}
	}
	cout << max << endl;
	cout << n + 1 << endl;
}