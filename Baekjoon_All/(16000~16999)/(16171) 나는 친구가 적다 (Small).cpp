#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, s1;
	string s2 = "";
	cin >> s >> s1;
	for (int i = 0; i < s.size(); i++) {
		if (!(s[i] >= '0' && s[i] <= '9'))
			s2 += s[i];
	}
	if (s2.find(s1) != string::npos)
		cout << 1;
	else
		cout << 0;

	return 0;
}