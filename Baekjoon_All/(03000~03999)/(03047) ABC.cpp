#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int A, B, C;
	int arr[3];
	string str;
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
	cin >> str;
	sort(arr, arr + 3);
	A = arr[0];
	B = arr[1];
	C = arr[2];
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'A') {
			cout << A << " ";
		}
		else if (str[i] == 'B') {
			cout << B << " ";
		}
		else if (str[i] == 'C') {
			cout << C << " ";
		}
	}

	return 0;
}