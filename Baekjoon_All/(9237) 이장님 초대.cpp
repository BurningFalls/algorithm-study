#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

bool compare(int a, int b) {
	return a > b;
}

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N;
	int maximum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N, compare);
	for (int i = 0; i < N; i++) {
		maximum = max(maximum, arr[i] + 1 + i);
	}
	cout << maximum + 1;

	return 0;
}