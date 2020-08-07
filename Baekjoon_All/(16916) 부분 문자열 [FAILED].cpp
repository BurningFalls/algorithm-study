#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	string sub_str;
	int i = 0;
	int j = 0;
	int cnt = 0;
	cin >> str;
	cin >> sub_str;
	while (i < sub_str.size() && j < str.size()) {
		if (sub_str[i] == str[j]) {
			i++;
			j++;
			cnt++;
		}
		else {
			j = j - cnt + 1;
			i = 0;
			cnt = 0;
		}
	}
	if (cnt == sub_str.size())
		cout << "1";
	else
		cout << "0";

	return 0;
}