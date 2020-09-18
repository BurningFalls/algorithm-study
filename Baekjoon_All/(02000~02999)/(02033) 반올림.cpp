#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	int N;
	int len;
	int temp;
	cin >> N;
	len = to_string(N).size();
	if (len == 1) {
		cout << N;
	}
	else {
		for (int i = 2; i <= len; i++) {
			temp = (N / int(pow(10, i - 2))) % 10;
			if (temp >= 5) {
				N = ((N / int(pow(10, i - 1))) + 1) * int(pow(10, i - 1));
			}
			else if (temp <= 4) {
				N = (N / int(pow(10, i - 1))) * int(pow(10, i - 1));
			}
		}
		cout << N;
	}
	return 0;
}