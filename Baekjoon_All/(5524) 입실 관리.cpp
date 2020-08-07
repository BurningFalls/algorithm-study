#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string str;
	char temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (int(str[j]) >= 65 && int(str[j]) <= 90) {
				temp = (str[j] + 32 - 97) % 26 + 97;
				cout << temp;
			}
			else {
				cout << str[j];
			}
		}
		cout << "\n";
	}

	return 0;
}