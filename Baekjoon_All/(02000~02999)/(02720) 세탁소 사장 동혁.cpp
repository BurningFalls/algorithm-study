#include <iostream>
using namespace std;

int main() {
	int T;
	int C;
	int arr[4];
	int temp;
	cin >> T;
	for (int a = 0; a < T; a++) {
		for (int i = 0; i < 4; i++) {
			arr[i] = 0;
		}
		cin >> C;
		temp = C;
		while (temp - 25 >= 0) {
			temp -= 25;
			arr[0]++;
		}
		while (temp - 10 >= 0) {
			temp -= 10;
			arr[1]++;
		}
		while (temp - 5 >= 0) {
			temp -= 5;
			arr[2]++;
		}
		while (temp - 1 >= 0) {
			temp -= 1;
			arr[3]++;
		}
		for (int i = 0; i < 4; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}