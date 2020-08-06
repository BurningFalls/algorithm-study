#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	while (true) {
		getline(cin, str);
		if (str == "END")
			break;
		reverse(str.begin(), str.end());
		cout << str << "\n";
	}

	return 0;
}