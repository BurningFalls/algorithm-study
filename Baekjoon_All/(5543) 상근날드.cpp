#include <iostream>
using namespace std;

int main() {
	int arr1[3];
	int arr2[2];
	int min1, min2;
	for (int i = 0; i < 3; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < 2; i++) {
		cin >> arr2[i];
	}
	min1 = arr1[0];
	min2 = arr2[0];
	for (int i = 1; i < 3; i++) {
		if (min1 > arr1[i]) {
			min1 = arr1[i];
		}
	}
	for (int i = 1; i < 2; i++) {
		if (min2 > arr2[i]) {
			min2 = arr2[i];
		}
	}
	cout << min1 + min2 - 50 << endl;
}

