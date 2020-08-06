#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	int ab[26] = { 0, };
	char temp = ' ';
	cin >> N;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		ab[str[0] - 97] += 1;
	}
	for (int i = 0; i < 26; i++) {
		if (ab[i] >= 5) {
			temp = i + 97;
			cout << temp;
		}
	}
	if (temp == ' ') {
		cout << "PREDAJA";
	}

	return 0;
}