#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i += 10) {
		cout << str.substr(i, 10) << "\n";
	}


	return 0;
}