#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string s;
	char temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		cout << "String #" << i + 1 << "\n";
		for (int i = 0; i < s.size(); i++) {
			temp = s[i] + 1;
			if (temp == 91) {
				temp = 65;
			}
			cout << temp;
		}
		cout << "\n\n";
	}

	return 0;
}