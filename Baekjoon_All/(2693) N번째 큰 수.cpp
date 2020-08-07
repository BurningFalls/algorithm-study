#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	int arr[10];
	cin >> T;
	for (int a = 0; a < T; a++) {
		for (int i = 0; i < 10; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + 10);
		cout << arr[7] << "\n";
	}

	return 0;
}