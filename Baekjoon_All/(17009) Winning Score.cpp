#include <iostream>
using namespace std;

int main() {
	int A, B;
	int arr[6];
	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
	}
	A = arr[0] * 3 + arr[1] * 2 + arr[2] * 1;
	B = arr[3] * 3 + arr[4] * 2 + arr[5] * 1;
	if (A > B)
		cout << "A";
	else if (A < B)
		cout << "B";
	else if (A == B)
		cout << "T";

	return 0;
}