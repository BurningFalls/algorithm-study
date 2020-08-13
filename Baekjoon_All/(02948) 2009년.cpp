#include <iostream>
using namespace std;

int main() {
	int D, M;
	int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	string str[7] = { "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday" };
	int sum = 0;

	cin >> D >> M;

	for (int i = 0; i < M - 1; i++) {
		sum += arr[i];
	}
	sum += D;
	cout << str[sum % 7];

	return 0;
}