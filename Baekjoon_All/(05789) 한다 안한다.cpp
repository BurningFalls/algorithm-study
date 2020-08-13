#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string str;
	int len;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		len = str.size();
		if (str[len / 2 - 1] == str[len / 2])
			cout << "Do-it\n";
		else
			cout << "Do-it-Not\n";
	}


	return 0;
}