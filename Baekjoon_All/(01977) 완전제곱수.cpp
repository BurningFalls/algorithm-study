#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	int M, N;
	int sum = 0;
	int min = 0;
	int temp;
	cin >> M >> N;
	temp = int(sqrt(M));
	if (temp * temp != M) {
		temp += 1;
	}
	for (int i = temp; i <= int(sqrt(N)); i++) {
		if (sum == 0) {
			min = i * i;
		}
		sum += i * i;
	}
	if (sum == 0) {
		cout << -1 << endl;
	}
	else {
		cout << sum << endl;
		cout << min << endl;
	}

	return 0;
}