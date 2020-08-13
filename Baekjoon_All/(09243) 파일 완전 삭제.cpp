#include <iostream>
#include <string>
using namespace std;

int N;
string str1, str2;

bool Check() {
	int len;
	len = str1.size();
	if (N % 2 == 1) {
		for (int i = 0; i < len; i++) {
			if (str1[i] == '1' && str2[i] == '0')
				continue;
			else if (str1[i] == '0' && str2[i] == '1')
				continue;
			else
				return false;
		}
	}
	else if (N % 2 == 0) {
		for (int i = 0; i < len; i++) {
			if (str1[i] == '0' && str2[i] == '0')
				continue;
			else if (str1[i] == '1' && str2[i] == '1')
				continue;
			else
				return false;
		}
	}
	return true;
}

int main() {
	cin >> N;
	cin >> str1;
	cin >> str2;
	if (Check())
		cout << "Deletion succeeded";
	else
		cout << "Deletion failed";

	return 0;
}