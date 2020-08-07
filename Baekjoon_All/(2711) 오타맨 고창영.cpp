#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	int num;
	string str;
	string t_str1, t_str2;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> num >> str;
		t_str1 = str.substr(0, num - 1);
		t_str2 = str.substr(num, str.size() - num);
		cout << t_str1 + t_str2 << "\n";
	}

	return 0;
}