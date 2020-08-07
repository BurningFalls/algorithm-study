#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> str;
		cout << str[0] << str[str.size() - 1] << "\n";
	}

	return 0;
}