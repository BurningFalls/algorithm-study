#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int C, K;
	cin >> C >> K;
	if (C < int(pow(10, K))) {
		if (C / int(pow(10, K - 1)) >= 5) {
			cout << int(pow(10, K));
		}
		else {
			cout << 0;
		}
	}
	else {
		cout << int(round(C / int(pow(10, K))) * int(pow(10, K)));
	}
	return 0;
}