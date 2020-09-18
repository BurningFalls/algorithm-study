#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	float* arr = new float[N];
	int max;
	float sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	max = arr[0];
	for (int i = 1; i < N; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	for (int i = 0; i < N; i++) {
		arr[i] = arr[i] / max * 100;
	}
	for (int i = 0; i < N; i++) {
		sum += arr[i];
	}
	cout << sum / N << endl;
}