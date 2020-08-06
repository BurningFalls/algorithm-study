#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int N;
	int i = 0;
	int sum = 0;
	cin >> N;

	while (true) {
		if (N >= 9 * pow(10, i)) {
			N -= 9 * pow(10, i);
			sum += 9 * pow(10, i) * (i + 1);
		}
		else {
			sum += N * (i + 1);
			break;
		}
		i++;
	}
	cout << sum << endl;

	return 0;
}