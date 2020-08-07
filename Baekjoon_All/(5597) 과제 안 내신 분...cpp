#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[28];
	int all[30] = { 0, };
	for (int i = 0; i < 28; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 28; i++) {
		all[arr[i] - 1] = 1;
	}
	for (int i = 0; i < 30; i++) {
		if (all[i] == 0) {
			cout << i + 1 << "\n";
		}
	}

	return 0;
}