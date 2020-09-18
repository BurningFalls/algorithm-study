#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	int arr[10001];
	long long int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum += abs(arr[i] - arr[j]);
		}
	}
	cout << sum;

	return 0;
}