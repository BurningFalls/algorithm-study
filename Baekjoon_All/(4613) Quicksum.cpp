#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int sum;
	int len;
	while (true) {
		sum = 0;
		getline(cin, str);
		if (str == "#")
			break;
		len = str.size();
		for (int i = 0; i < len; i++) {
			if (str[i] == ' ') continue;
			sum += (i + 1) * (str[i] - 'A' + 1);
		}
		cout << sum << "\n";
	}

	return 0;
}