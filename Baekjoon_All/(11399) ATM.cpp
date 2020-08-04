#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int arr[1001];
	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		sum += arr[i] * (N - i);
	}
	cout << sum;

	return 0;
}