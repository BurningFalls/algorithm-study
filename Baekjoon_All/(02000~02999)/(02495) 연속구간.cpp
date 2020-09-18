#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int Check(string s) {
	int len = s.size();
	int cnt = 0;
	int max_cnt = 0;
	for (int i = 0; i < len - 1; i++) {
		if (s[i] == s[i + 1]) {
			cnt++;
		}
		else {
			max_cnt = max(max_cnt, cnt + 1);
			cnt = 0;
		}
	}
	max_cnt = max(max_cnt, cnt + 1);
	return max_cnt;
}

int main() {
	string str;
	for (int i = 0; i < 3; i++) {
		cin >> str;
		cout << Check(str) << "\n";
	}

	return 0;
}