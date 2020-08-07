#include <iostream>
using namespace std;

int main() {
	int arr[10];
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 10; i++) {
		sum += arr[i];
		if (sum > 100) {
			if (sum - 100 <= 100 - (sum - arr[i])) {
				cout << sum;
				break;
			}
			else if (sum - 100 > 100 - (sum - arr[i])) {
				cout << sum - arr[i];
				break;
			}
		}
	}
	if (sum <= 100) {
		cout << sum << endl;
	}

	return 0;
}