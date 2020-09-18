#include <iostream>
#include <math.h>
using namespace std;

bool check(int n) {
	if (n == 1) {
		return false;
	}
	else if (n == 2) {
		return true;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int N;
	int count = 0;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		if (check(arr[i])) {
			count++;
		}
	}
	cout << count << endl;

	return 0;
}