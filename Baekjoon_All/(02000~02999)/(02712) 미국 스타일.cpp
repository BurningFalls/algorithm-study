#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	int T;
	double num;
	string str;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> num >> str;
		cout << fixed << setprecision(4);
		if (str == "kg")
			cout << num * 2.2046 << " lb" << "\n";
		else if (str == "l")
			cout << num * 0.2642 << " g" << "\n";
		else if (str == "lb")
			cout << num * 0.4536 << " kg" << "\n";
		else if (str == "g")
			cout << num * 3.7854 << " l" << "\n";
	}


	return 0;
}