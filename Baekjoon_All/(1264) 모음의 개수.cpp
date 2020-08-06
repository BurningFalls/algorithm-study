#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int len;
	bool flag;
	int cnt;
	char arr[11] = { 'a','e','i','o','u','A','E','I','O','U' };
	while (true) {
		getline(cin, str);
		if (str == "#")
			break;
		len = str.size();
		cnt = 0;
		for (int i = 0; i < len; i++) {
			flag = false;
			for (int j = 0; j < 10; j++) {
				if (str[i] == arr[j]) {
					flag = true;
					break;
				}
			}
			if (flag) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}