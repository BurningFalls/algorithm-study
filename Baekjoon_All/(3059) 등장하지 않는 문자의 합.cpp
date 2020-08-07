#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	string str;
	int sum;
	int len;
	cin >> T;
	for (int a = 0; a < T; a++) {
		bool Check[27] = { 0, };
		sum = 0;
		cin >> str;
		len = str.size();
		for (int i = 0; i < len; i++) {
			Check[str[i] - 65] = 1;
		}
		for (int i = 0; i < 26; i++) {
			if (Check[i] == 0)
				sum += (65 + i);
		}
		cout << sum << "\n";
	}

	return 0;
}