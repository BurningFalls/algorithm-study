#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int N;
	int A[51];
	int B[51];
	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	sort(A, A + N, compare);
	sort(B, B + N);
	for (int i = 0; i < N; i++) {
		sum += A[i] * B[i];
	}

	cout << sum;

	return 0;
}