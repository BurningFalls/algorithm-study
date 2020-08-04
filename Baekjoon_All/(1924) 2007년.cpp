#include <iostream>
using namespace std;

int main() {
	int x, y;
	int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	string str[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int sum = 0;

	cin >> x >> y;

	for (int i = 0; i < x - 1; i++) {
		sum += arr[i];
	}
	sum += y;
	cout << str[sum % 7];

	return 0;
}