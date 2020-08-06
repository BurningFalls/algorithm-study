#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	char c[6] = { 'a', 'e', 'i', 'o', 'u' };
	int cnt = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 5; j++) {
			if (s[i] == c[j]) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;

	return 0;
}