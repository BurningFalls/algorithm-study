#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int mt1, mt2;
	bool flag = false;
	cin >> s;
	for (int i = 0; i < s.size() - 1; i++) {
		mt1 = 1, mt2 = 1;
		for (int j = 0; j <= i; j++) {
			mt1 *= s[j] - '0';
		}
		for (int j = i + 1; j < s.size(); j++) {
			mt2 *= s[j] - '0';
		}
		if (mt1 == mt2) {
			flag = true;
			break;
		}
	}
	if (flag == false) {
		cout << "NO" << endl;
	}
	else if (flag == true) {
		cout << "YES" << endl;
	}


	return 0;
}