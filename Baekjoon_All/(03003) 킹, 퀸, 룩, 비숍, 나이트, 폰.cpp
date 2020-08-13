#include <iostream>
using namespace std;

int main() {
	int arr[6];
	int ans[6] = { 1, 1, 2, 2, 2, 8 };
	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 6; i++) {
		cout << ans[i] - arr[i] << " ";
	}



	return 0;
}