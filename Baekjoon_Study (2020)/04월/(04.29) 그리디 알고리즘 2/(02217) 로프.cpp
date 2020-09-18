#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N;
	int maximum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		maximum = max(maximum, arr[i] * (N - i));
	}
	cout << maximum;

	return 0;
}