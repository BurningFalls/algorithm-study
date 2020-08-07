#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	int N;
	int arr[21];
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		cout << 2 * (*max_element(arr, arr + N) - *min_element(arr, arr + N)) << "\n";
	}

	return 0;
}