#include <iostream>
using namespace std;

int main() {
	int X;
	cin >> X;
	int i = 0;
	int temp;
	while (true) {
		if ((i * i + i) / 2 + 1 <= X && (i * i + 3 * i) / 2 + 1 >= X) {
			if (i % 2 == 0) {
				temp = (i + 1) - (X - ((i * i + i) / 2 + 1));
				cout << temp << "/" << (i + 2) - temp << endl;
			}
			else if (i % 2 != 0) {
				temp = (X - ((i * i + i) / 2 + 1)) + 1;
				cout << temp << "/" << (i + 2) - temp << endl;
			}
			break;
		}
		i++;
	}
	/*
	0 -> 1		- 1
	1 -> 2~3	- 1 2
	2 -> 4~6	- 3 2 1
	3 -> 7~10	- 1 2 3 4
	4 -> 11~15	- 5 4 3 2 1

	1,2,4,7,11 -> 1, 1+1, 1+1+2, 1+1+2+3, 1+1+2+3+4...
	-> 1+i(i+1)/2 = (i^2+i)/2+1

	1,3,6,10,15 -> 1, 2+1, 4+2, 7+3, 11+4, ... (앞의 수와 연관지어)
	-> ((i^2+i)/2+1)+i = (i^2+3i)/2+1-
	*/


	return 0;
}