#include <iostream>
using namespace std;

int A[500001];

int main() {
	int N;
	int num = 1;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++) {
		if (A[i] == num) {
			num++;
		}
	}
	num--;
	cout << N - num + 1;

	return 0;
}