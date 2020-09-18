#include <iostream>
using namespace std;

int main() {
	int N;
	int arr[100][10];
	int count;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		count = 0;
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == j % 5 + 1) {
				count++;
			}
		}
		if (count == 10) {
			cout << i + 1 << endl;
		}
	}

	return 0;
}