#include <iostream>
#include <string>
using namespace std;

char aei[6] = { 'a', 'e', 'i', 'o', 'u', ' ' };

bool con1(string s) {
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 5; j++) {
			if (s[i] == aei[j]) {
				return true;
			}
		}
	}
	return false;
}

bool con2(string s) {
	int aei_flag = false;
	int bcd_flag = false;
	int bcd_count = 0;
	int aei_count = 0;
	int cnt;
	for (int i = 0; i < s.size(); i++) {
		cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (s[i] == aei[j]) {
				cnt = 1;
				break;
			}
		}
		if (cnt == 1) {
			bcd_flag = false;
			if (aei_flag == true) {
				aei_count++;
			}
			if (aei_flag == false) {
				aei_flag = true;
				aei_count = 1;
			}
		}
		if (cnt == 0) {
			aei_flag = false;
			if (bcd_flag == true) {
				bcd_count++;
			}
			if (bcd_flag == false) {
				bcd_flag = true;
				bcd_count = 1;
			}
		}
		if (aei_count >= 3 || bcd_count >= 3) {
			return false;
		}
	}
	return true;
}

bool con3(string s) {
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == s[i + 1]) {
			if (s[i] == 'e' || s[i] == 'o') {
				continue;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

int main() {
	string s;
	while (true) {
		cin >> s;
		if (s == "end") {
			break;
		}
		if (con1(s) && con2(s) && con3(s)) {
			cout << "<" << s << "> is acceptable." << "\n";
		}
		else {
			cout << "<" << s << "> is not acceptable." << "\n";
		}
	}

	return 0;
}