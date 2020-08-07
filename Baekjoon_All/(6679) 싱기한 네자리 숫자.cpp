#include <iostream>
using namespace std;

int main() {
	int temp;
	int ten_sum;
	int twelve_sum;
	int sixteen_sum;
	for (int num = 1000; num <= 9999; num++) {
		ten_sum = 0;
		twelve_sum = 0;
		sixteen_sum = 0;
		temp = num;
		while (temp != 0) {
			ten_sum += temp % 10;
			temp /= 10;
		}
		temp = num;
		while (temp != 0) {
			twelve_sum += temp % 12;
			temp /= 12;
		}
		temp = num;
		while (temp != 0) {
			sixteen_sum += temp % 16;
			temp /= 16;
		}
		if (ten_sum == twelve_sum && ten_sum == sixteen_sum) {
			cout << num << endl;
		}
	}

	return 0;
}