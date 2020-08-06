#include <iostream>
using namespace std;

int main() {
	int n;
	bool flag = true;
	cin >> n;
	while (n > 1) {
		if (n % 2 == 0)
			n /= 2;
		else {
			flag = false;
			break;
		}
	}
	if (flag == false)
		cout << "0";
	else if (flag == true)
		cout << "1";

	return 0;
}