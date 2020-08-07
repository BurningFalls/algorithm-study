#include <iostream>
using namespace std;

int main() {
	int arr[10];
	int check[1001] = { 0, };
	int sum = 0;
	int maximum = 0;
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		check[arr[i]] += 1;
		sum += arr[i];
	}
	for (int i = 10; i <= 1000; i += 10) {
		if (check[i]) {
			if (maximum < check[i]) {
				ans = i;
				maximum = check[i];
			}
		}
	}
	cout << sum / 10 << "\n" << ans;

	return 0;
}