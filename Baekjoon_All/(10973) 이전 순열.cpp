#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int arr[10001];
	bool flag;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	flag = prev_permutation(arr, arr + N);
	if (flag == false)
		cout << -1;
	else {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
	}

	return 0;
}