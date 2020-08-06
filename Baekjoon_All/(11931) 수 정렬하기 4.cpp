#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];

bool compare(int a, int b) {
	return a > b;
}

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N, compare);
	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}