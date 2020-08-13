#include <iostream>
using namespace std;

int main() {
	int arr[1001] = { 0, };
	int num = 1;
	int cnt = 0;
	int sum = 0;
	int A, B;
	cin >> A >> B;
	for (int i = 1; i <= 1000; i++) {
		arr[i] = num;
		cnt++;
		if (cnt == num) {
			num++;
			cnt = 0;
		}
	}
	for (int i = A; i <= B; i++) {
		sum += arr[i];
	}
	cout << sum;

	return 0;
}