#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int arr[1001];
	int sum_arr[1001];
	bool flag = false;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	if (arr[0] != 1)
		cout << 1;
	else {
		sum_arr[0] = 1;
		for (int i = 1; i < N; i++) {
			if (sum_arr[i - 1] + 1 < arr[i]) {
				cout << sum_arr[i - 1] + 1;
				flag = true;
				break;
			}
			else {
				sum_arr[i] = sum_arr[i - 1] + arr[i];
			}
		}
		if (!flag)
			cout << sum_arr[N - 1] + 1;
	}

	return 0;
}