#include <iostream>
using namespace std;

int func(int tc, int fc, int n) {
	for (int i = fc; i >= 0; i--) {
		for (int j = tc; j >= 0; j--) {
			if (5 * i + 3 * j == n) {
				return (i + j);
			}
		}
	}
	return -1;
}

int main() {
	int N;
	int temp_n;
	int three_count = 0;
	int five_count = 0;
	cin >> N;
	temp_n = N;
	while (temp_n >= 3) {
		temp_n = temp_n - 3;
		three_count++;
	}
	temp_n = N;
	while (temp_n >= 5) {
		temp_n = temp_n - 5;
		five_count++;
	}
	cout << func(three_count, five_count, N) << endl;

	return 0;
}