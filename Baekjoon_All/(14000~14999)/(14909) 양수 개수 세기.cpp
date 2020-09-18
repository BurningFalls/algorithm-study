#include <iostream>
#include <string>
using namespace std;

int main() {
	int blank_num = 0;
	int minus_num = 0;
	string str;
	int sub_cnt = 0;
	int zero_cnt = 0;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ')
			blank_num++;
		else if (str[i] == '-')
			minus_num++;
		else if (str[i] == '0') {
			if (i == 0 || str[i - 1] == ' ') {
				zero_cnt++;
			}
		}
	}
	cout << blank_num + 1 - minus_num - zero_cnt;

	return 0;
}