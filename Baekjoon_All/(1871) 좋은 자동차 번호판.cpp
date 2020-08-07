#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool Check(string s) {
	int res1 = 0, res2 = 0;
	res1 = (s[0] - 65) * 26 * 26 + (s[1] - 65) * 26 + (s[2] - 65);
	res2 = (s[4] - '0') * 1000 + (s[5] - '0') * 100 + (s[6] - '0') * 10 + (s[7] - '0');
	if (abs(res1 - res2) <= 100)
		return true;
	else
		return false;
}

int main() {
	int N;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (Check(str))
			cout << "nice\n";
		else
			cout << "not nice\n";
	}


	return 0;
}