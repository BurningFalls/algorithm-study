#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int arr[26] = { 0, };
	int len;
	int maximum = 0;
	char X;
	while (getline(cin, str)) {
		len = str.size();
		for (int i = 0; i < len; i++) {
			arr[str[i] - 'a']++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (maximum < arr[i])
			maximum = arr[i];
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] == maximum) {
			X = i + 'a';
			cout << X;
		}
	}

	return 0;
}