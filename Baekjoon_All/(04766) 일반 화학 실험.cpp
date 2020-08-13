#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double temp1 = -1, temp2 = -1;
	int num = 0;
	while (true) {
		if (num == 0)
			cin >> temp1;
		else if (num == 1)
			cin >> temp2;
		if (temp1 == 999 || temp2 == 999)
			break;
		if (temp1 != -1 && temp2 != -1) {
			if (num == 0)
				cout << fixed << setprecision(2) << temp1 - temp2 << "\n";
			else if (num == 1)
				cout << fixed << setprecision(2) << temp2 - temp1 << "\n";
		}

		num++;
		if (num == 2)
			num = 0;
	}


	return 0;
}