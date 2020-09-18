#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int len = s.size();
	int ans[26];

	for (int i = 0; i < 26; i++) {
		ans[i] = -1;
	}
	for (int i = 0; i < len; i++) {
		if (ans[s[i] - 97] == -1) {
			ans[s[i] - 97] = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}