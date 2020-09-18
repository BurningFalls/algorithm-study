#include <iostream>
using namespace std;

int main() {
	int L, P;
	int temp;
	int arr[5];
	cin >> L >> P;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	temp = L * P;
	for (int i = 0; i < 5; i++) {
		cout << arr[i] - temp << " ";
	}

	return 0;
}