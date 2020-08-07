#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string str1, str2;
	int len1, len2;
	int len;
	vector<int> v;
	cin >> str1 >> str2;
	len1 = str1.size();
	len2 = str2.size();
	if (len1 > len2) {
		reverse(str2.begin(), str2.end());
		for (int i = 0; i < len1 - len2; i++) {
			str2.push_back('0');
		}
		reverse(str1.begin(), str1.end());
	}
	else if (len1 < len2) {
		reverse(str1.begin(), str1.end());
		for (int i = 0; i < len2 - len1; i++) {
			str1.push_back('0');
		}
		reverse(str2.begin(), str2.end());
	}
	else {
		reverse(str1.begin(), str1.end());
		reverse(str2.begin(), str2.end());
	}
	for (int i = 0; i < max(len1, len2); i++) {
		v.push_back((str1[i] - '0') + (str2[i] - '0'));
	}
	len = v.size();
	for (int i = 0; i < len; i++) {
		cout << v[len - i - 1];
	}

	return 0;
}