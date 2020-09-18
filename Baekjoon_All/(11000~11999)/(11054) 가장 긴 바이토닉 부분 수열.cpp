#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* arr = new int[N + 1];
	int* dp_left = new int[N + 1];
	int* dp_right = new int[N + 1];
	int* dp_sum = new int[N + 1];
	int maximum;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dp_left[1] = 1;
	dp_right[N] = 1;
	for (int i = 2; i <= N; i++) {
		maximum = 0;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i] && maximum < dp_left[j]) {
				maximum = dp_left[j];
			}
		}
		dp_left[i] = maximum + 1;
	}
	for (int i = N - 1; i >= 1; i--) {
		maximum = 0;
		for (int j = N; j > i; j--) {
			if (arr[j] < arr[i] && maximum < dp_right[j]) {
				maximum = dp_right[j];
			}
		}
		dp_right[i] = maximum + 1;
	}
	for (int i = 1; i <= N; i++) {
		dp_sum[i] = dp_left[i] + dp_right[i] - 1;
	}
	cout << *max_element(dp_sum + 1, dp_sum + N + 1) << endl;


	return 0;
}