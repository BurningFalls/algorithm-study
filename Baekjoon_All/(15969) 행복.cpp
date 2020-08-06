#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int arr[1001];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cout << arr[N - 1] - arr[0];

	return 0;
}