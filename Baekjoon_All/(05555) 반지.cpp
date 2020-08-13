#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	string s;
	int N;
	int cnt = 0;
	int len;
	cin >> str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		len = s.size();
		for (int j = 0; j < min(len, 10); j++) {
			s += s[j];
		}
		if (s.find(str) != string::npos) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}