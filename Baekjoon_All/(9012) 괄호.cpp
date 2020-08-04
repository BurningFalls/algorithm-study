#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Check(string str) {
	vector<int> v;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			v.push_back(1);
		}
		else if (str[i] == ')') {
			if (v.empty())
				return false;
			else
				v.pop_back();
		}
	}
	if (v.empty())
		return true;
	else
		return false;
}

int main() {
	int T;
	string str;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> str;
		if (Check(str))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}