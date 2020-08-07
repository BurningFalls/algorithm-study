#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1, str2;
	int len1, len2;
	int cnt;
	bool flag;
	int casee = 1;
	while (true) {
		int num1[26] = { 0, };
		int num2[26] = { 0, };
		flag = true;
		cnt = 0;
		cin >> str1 >> str2;
		if (str1 == "END" && str2 == "END")
			break;
		len1 = str1.size();
		len2 = str2.size();
		if (len1 != len2) {
			flag = false;
		}
		else {
			for (int i = 0; i < len1; i++) {
				num1[str1[i] - 'a']++;
			}
			for (int i = 0; i < len2; i++) {
				num2[str2[i] - 'a']++;
			}
			for (int i = 0; i < 26; i++) {
				if (num1[i] != num2[i]) {
					flag = false;
					break;
				}
			}
		}
		cout << "Case " << casee << ": ";
		if (flag)
			cout << "same";
		else if (!flag)
			cout << "different";
		cout << "\n";
		casee++;
	}

	return 0;
}