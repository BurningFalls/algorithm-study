#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* arr = new int[N];
	int min, max;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	min = arr[0];
	max = arr[0];
	for (int i = 1; i < N; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	cout << min << " " << max << endl;
}