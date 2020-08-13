#include <iostream>
#include <string>
using namespace std;

int Func(string s) {
	if (s.size() == 1)
		return (s[0] - '0');
	else if (s.size() == 2)
		return (s[0] - '0') * 2 + (s[1] - '0');
	else if (s.size() == 3)
		return (s[0] - '0') * 4 + (s[1] - '0') * 2 + (s[2] - '0');
}

int main() {
	string str;
	int len;
	string sub_str = "";
	int temp;
	cin >> str;
	len = str.size();
	temp = len % 3;
	if (temp != 0) {
		sub_str = str.substr(0, temp);
		cout << Func(sub_str);
	}
	for (int i = temp; i < len; i += 3) {
		sub_str = str.substr(i, 3);
		cout << Func(sub_str);
	}

	return 0;
}