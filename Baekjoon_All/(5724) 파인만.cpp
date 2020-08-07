#include <iostream>
using namespace std;

int main() {
	int N;
	int arr[101];
	arr[1] = 1;
	for (int i = 2; i <= 100; i++) {
		arr[i] = arr[i - 1] + i * i;
	}
	while (true) {
		cin >> N;
		if (N == 0)
			break;
		cout << arr[N] << "\n";
	}

	return 0;
}