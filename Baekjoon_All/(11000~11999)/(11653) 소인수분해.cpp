#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 2; i <= N || N > 1; i++) {
		if (N % i == 0) {
			N /= i;
			cout << i << "\n";
			i--;
		}
	}

	return 0;
}