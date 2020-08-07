#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string str;
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		getline(cin, str);
		if (str[0] >= 97 && str[0] <= 122)
			str[0] = str[0] - 32;
		cout << str << "\n";
	}

	return 0;
}