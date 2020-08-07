#include <iostream>
using namespace std;

int main() {
	int num;
	int maximum;
	int yloc, xloc;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> num;
			if (i == 0 && j == 0)
				maximum = num;
			else {
				if (maximum < num) {
					maximum = num;
					yloc = i + 1;
					xloc = j + 1;
				}
			}
		}
	}
	cout << maximum << "\n" << yloc << " " << xloc;

	return 0;
}