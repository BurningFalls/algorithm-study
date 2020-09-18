#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1, str2;
	int cnt1 = 0, cnt2 = 0;
	cin >> str1;
	cin >> str2;
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] == 'a')
			cnt1++;
	}
	for (int i = 0; i < str2.size(); i++) {
		if (str2[i] == 'a')
			cnt2++;
	}
	if (cnt1 >= cnt2)
		cout << "go";
	else
		cout << "no";

	return 0;
}