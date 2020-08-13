#include <iostream>
using namespace std;

int arr[3];

void sort() {
	int temp;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int a, b, c;

	while (true) {
		cin >> a >> b >> c;
		arr[0] = a;
		arr[1] = b;
		arr[2] = c;
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		sort();
		if (arr[2] * arr[2] == arr[1] * arr[1] + arr[0] * arr[0]) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}
	return 0;
}