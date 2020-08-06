#include <iostream>
using namespace std;

int main() {
	int N;
	int temp;
	cin >> N;
	if (N == 1)
		cout << 1;
	else {
		temp = (N - 2) % 8;
		if (temp == 7)
			cout << 1;
		else if (temp == 6 || temp == 0)
			cout << 2;
		else if (temp == 5 || temp == 1)
			cout << 3;
		else if (temp == 4 || temp == 2)
			cout << 4;
		else if (temp == 3)
			cout << 5;
	}

	return 0;
}