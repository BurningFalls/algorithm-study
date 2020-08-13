#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	string ans = "";
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 65 && str[i] <= 90)
			ans += str[i];
	}
	cout << ans;

	return 0;
}