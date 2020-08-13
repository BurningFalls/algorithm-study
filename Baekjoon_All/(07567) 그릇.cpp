#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int len;
	int ans = 10;
	cin >> str;
	len = str.size();
	for (int i = 0; i < len - 1; i++) {
		if (str[i] != str[i + 1]) {
			ans += 10;
		}
		else
			ans += 5;
	}
	cout << ans;

	return 0;
}