#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int decomposition_sum(int goal) {
	for (int i = 1; i <= goal; i++) {
		int len = to_string(i).size();
		int sum = i;
		for (int j = 0; j < len; j++) {
			sum += (i / int(pow(10, j))) % 10;
		}
		if (sum == goal) {
			return i;
		}
	}
	return 0;
}

int main() {
	int N;
	int len;
	int sum;
	cin >> N;
	cout << decomposition_sum(N);

	return 0;
}