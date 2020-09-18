#include <iostream>
using namespace std;

int main() {
	int a;
	int b;
	cin >> a;
	cin >> b;
	cout << a * (b % 10) << endl;
	cout << a * (b / 10 % 10) << endl;
	cout << a * (b / 100) << endl;
	cout << a * (b % 10) + a * (b / 10 % 10) * 10 + a * (b / 100) * 100 << endl;


	return 0;
}