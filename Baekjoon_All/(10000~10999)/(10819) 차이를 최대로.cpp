#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int N;
	int arr[9];
	bool flag = true;
	int result;
	int result_max = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	while (flag) {
		result = 0;
		for (int i = 0; i < N - 1; i++) {
			result += abs(arr[i] - arr[i + 1]);
		}
		result_max = max(result_max, result);
		flag = next_permutation(arr, arr + N);
	}
	cout << result_max;

	return 0;
}