#include <iostream>
using namespace std;

int main() {
	int arr[3];
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	if (arr[0] == 60 && arr[1] == 60 && arr[2] == 60)
		cout << "Equilateral";
	else if (sum == 180 && (arr[0] != arr[1]) && (arr[0] != arr[2]) && (arr[1] != arr[2]))
		cout << "Scalene";
	else if (sum != 180)
		cout << "Error";
	else
		cout << "Isosceles";

	return 0;
}