#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* arr = new int[N];
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}