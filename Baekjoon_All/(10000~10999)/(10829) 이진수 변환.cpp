#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	long long int a;
	string str = "";
	cin >> a;
	while (a > 0) {
		if (a % 2 == 0)
			str += "0";
		else if (a % 2 == 1)
			str += "1";
		a /= 2;
	}
	reverse(str.begin(), str.end());
	cout << str;

	return 0;
}