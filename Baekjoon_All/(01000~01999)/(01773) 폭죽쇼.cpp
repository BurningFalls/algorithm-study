#include <iostream>
using namespace std;

int main() {
	int N, C;
	cin >> N >> C;
	int* arr = new int[N];
	int* boom = new int[C + 1];
	int sum = 0;
	for (int i = 0; i <= C; i++) {
		boom[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 1; j * arr[i] <= C; j++) {
			boom[j * arr[i]] = 1;
		}
	}
	for (int i = 1; i <= C; i++) {
		sum += boom[i];
	}
	cout << sum << endl;

	return 0;
}