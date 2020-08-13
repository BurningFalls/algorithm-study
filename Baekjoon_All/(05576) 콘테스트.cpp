#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr1[10];
	int arr2[10];
	for (int i = 0; i < 10; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < 10; i++) {
		cin >> arr2[i];
	}
	sort(arr1, arr1 + 10);
	reverse(arr1, arr1 + 10);
	cout << arr1[0] + arr1[1] + arr1[2] << " ";
	sort(arr2, arr2 + 10);
	reverse(arr2, arr2 + 10);
	cout << arr2[0] + arr2[1] + arr2[2];

	return 0;
}