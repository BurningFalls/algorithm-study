#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	int num;
	int sum;
	int minimum;
	cin >> T;
	for (int a = 0; a < T; a++) {
		sum = 0;
		minimum = 101;
		for (int i = 0; i < 7; i++) {
			cin >> num;
			if (num % 2 == 0) {
				sum += num;
				minimum = min(minimum, num);
			}
		}
		cout << sum << " " << minimum << "\n";
	}

	return 0;
}