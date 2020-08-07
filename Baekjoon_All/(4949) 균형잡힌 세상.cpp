#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string str;
	vector<int> v;
	bool flag;
	while (true) {
		v.clear();
		flag = true;
		getline(cin, str);
		if (str == ".")
			break;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') {
				v.push_back(1);
			}
			else if (str[i] == '[') {
				v.push_back(2);
			}
			else if (str[i] == ')') {
				if (v.empty() || v.back() != 1) {
					flag = false;
					break;
				}
				else
					v.pop_back();
			}
			else if (str[i] == ']') {
				if (v.empty() || v.back() != 2) {
					flag = false;
					break;
				}
				else
					v.pop_back();
			}
		}
		if (flag && v.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}



	return 0;
}