#include <iostream>
using namespace std;

int main() {
	int arr[8];
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 8; i++) {
		if (arr[i] == i + 1) {
			cnt1++;
		}
		if (arr[i] == 8 - i) {
			cnt2++;
		}
	}
	if (cnt1 == 8)
		cout << "ascending";
	else if (cnt2 == 8)
		cout << "descending";
	else
		cout << "mixed";

	return 0;
}