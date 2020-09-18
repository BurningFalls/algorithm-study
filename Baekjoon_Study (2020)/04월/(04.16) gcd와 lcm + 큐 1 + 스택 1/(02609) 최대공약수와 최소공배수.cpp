#include <iostream>
#include <algorithm>
using namespace std;

int func(int a, int b) {
	for (int i = min(a, b); i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {
			return i;
		}
	}
}

int main() {
	int a, b;
	int temp;
	cin >> a >> b;
	temp = func(a, b);
	cout << temp << "\n";
	cout << a * b / temp;


	return 0;
}