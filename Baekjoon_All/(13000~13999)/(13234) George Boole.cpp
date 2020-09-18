#include <iostream>
using namespace std;

int main() {
	string s1, s2, s3;
	bool flag1, flag2;
	bool ans_flag;
	cin >> s1 >> s2 >> s3;
	if (s1 == "true")
		flag1 = true;
	else if (s1 == "false")
		flag1 = false;
	if (s3 == "true")
		flag2 = true;
	else if (s3 == "false")
		flag2 = false;
	if (s2 == "AND")
		ans_flag = flag1 && flag2;
	else if (s2 == "OR")
		ans_flag = flag1 || flag2;
	if (ans_flag == 1)
		cout << "true";
	else if (ans_flag == 0)
		cout << "false";

	return 0;
}