#include <iostream>
using namespace std;

int main() {
	int T;
	int arr[10001];
	int i = 0;
	int loc = 1;
	int num;
	cin >> T;
	while (loc <= 10000) {
		if (loc >= i * i + i && loc < i * i + 3 * i + 2) {
			arr[loc] = i;
			loc++;
		}
		else {
			i++;
		}
	}

	for (int a = 0; a < T; a++) {
		cin >> num;
		cout << arr[num] << "\n";
	}

	return 0;
}