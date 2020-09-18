#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	long long int arr[6];
	long long int sum = 0;
	cin >> N;
	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 6);
	if (N == 1) {
		for (int i = 0; i < 5; i++) {
			sum += arr[i];
		}
	}
	else {
		sum += 4 * (arr[0] + arr[1] + arr[2]);
		sum += 4 * (arr[0] + arr[1]) * (N - 1);
		sum += 4 * (arr[0] + arr[1]) * (N - 2);
		sum += (N - 2) * (N - 1) * arr[0] * 4;
		sum += (N - 2) * (N - 2) * arr[0];
	}

	cout << sum;

	return 0;
}