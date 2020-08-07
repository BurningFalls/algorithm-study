#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	string ans = "CAMBRIDGE";
	cin >> str;
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < str.size(); j++) {
			if (ans[i] == str[j])
				str[j] = ' ';
		}
	}
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') continue;
		cout << str[i];
	}


	return 0;
}