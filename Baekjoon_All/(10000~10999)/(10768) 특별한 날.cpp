#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int month, day;
	int temp;
	cin >> month;
	cin >> day;
	temp = month * 100 + day;
	if (temp < 218) {
		cout << "Before";
	}
	else if (temp > 218) {
		cout << "After";
	}
	else if (temp == 218) {
		cout << "Special";
	}


	return 0;
}