#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	if (N == 2) {
		for (int i = 1; i <= min(arr[0], arr[1]); i++) {
			if (arr[0] % i == 0 && arr[1] % i == 0) {
				cout << i << "\n";
			}
		}
	}
	else if (N == 3) {
		for (int i = 1; i <= min({ arr[0], arr[1], arr[2] }); i++) {
			if (arr[0] % i == 0 && arr[1] % i == 0 && arr[2] % i == 0) {
				cout << i << "\n";
			}
		}
	}

	return 0;
}