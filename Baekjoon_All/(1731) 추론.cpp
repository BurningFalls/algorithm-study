#include <iostream>
using namespace std;

int main() {
	int N;
	int arr[51];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	if (arr[2] - arr[1] == arr[1] - arr[0])
		cout << arr[N - 1] + (arr[1] - arr[0]);
	else if (arr[2] / arr[1] == arr[1] / arr[0])
		cout << arr[N - 1] * (arr[1] / arr[0]);

	return 0;
}