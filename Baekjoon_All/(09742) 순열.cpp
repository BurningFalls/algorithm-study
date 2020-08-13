#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	int num;
	bool flag;
	int x;
	bool x_flag;
	while (cin >> str >> num) {
		flag = true;
		x = 1;
		x_flag = false;
		cout << str << " " << num << " = ";
		while (flag) {
			if (x == num) {
				x_flag = true;
				break;
			}
			flag = next_permutation(str.begin(), str.end());
			x++;
		}
		if (x_flag)
			cout << str << "\n";
		else
			cout << "No permutation\n";
	}

	return 0;
}