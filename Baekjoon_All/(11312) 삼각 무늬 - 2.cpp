#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int T;
	double A, B;
	int temp;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> A >> B;
		temp = ceil(A / B);
		cout << (long long int)(pow(temp, 2)) << "\n";
	}


	return 0;
}