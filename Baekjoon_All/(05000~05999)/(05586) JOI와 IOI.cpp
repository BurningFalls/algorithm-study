#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	string str1 = "JOI";
	string str2 = "IOI";
	int one_cnt = 0;
	int two_cnt = 0;
	cin >> str;
	for (int i = 0; i < str.size() - 2; i++) {
		if (str.substr(i, 3) == str1) {
			one_cnt++;
		}
		if (str.substr(i, 3) == str2) {
			two_cnt++;
		}
	}
	cout << one_cnt << "\n" << two_cnt;


	return 0;
}