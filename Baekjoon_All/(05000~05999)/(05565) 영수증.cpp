#include <iostream>
using namespace std;

int main() {
	int total;
	int arr[9];
	int sum = 0;
	cin >> total;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	cout << total - sum;


	return 0;
}