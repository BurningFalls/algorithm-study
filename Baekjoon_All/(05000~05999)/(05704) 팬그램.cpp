#include <iostream>
#include <string>
using namespace std;

int main() {
	bool arr[26] = { 0, };
	string str;
	int sum;
	while (true) {
		sum = 0;
		for (int i = 0; i < 26; i++)
			arr[i] = 0;
		getline(cin, str);
		if (str == "*")
			break;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ' ') {
				arr[int(str[i]) - 97] = 1;
			}
		}
		for (int i = 0; i < 26; i++) {
			sum += arr[i];
		}
		if (sum == 26)
			cout << "Y\n";
		else
			cout << "N\n";
	}

	return 0;
}