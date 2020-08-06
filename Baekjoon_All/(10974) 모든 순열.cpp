#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int arr[10001];
	bool flag = true;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		arr[i - 1] = i;
	}
	while (flag) {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		flag = next_permutation(arr, arr + N);
	}

	return 0;
}