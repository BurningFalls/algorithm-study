#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int x = 0;
	if (N == 1) {
		cout << 1 << endl;
	}
	else {
		while (true) {
			if (N >= 3 * x * x + 3 * x + 2 && N <= 3 * x * x + 9 * x + 7) {
				cout << x + 2 << endl;
				break;
			}
			x++;
		}
	}
	/*
	1 -> 1
	2~7 -> 2
	8~19 -> 3
	20~37 -> 4

	2, 8, 20, ...
	a(0) = 2, a(1) = 2+6*1, a(2) = 2+6*(1+2), ...
	a(n) = 2+6*n*(n+1)/2 = 3n^2+3n+2

	7, 19, 37, ... (각 행의 앞 수와 연관지어 : 2, 8, 20...)
	a(0) = (2)+6-1, a(1) = (8)+6*2-1, a(2) = (20)+6*3-1, ...
	a(n) = (3n^2+3n+2)+6*(n+1)-1 = 3n^2+9n+7
	*/

	return 0;
}