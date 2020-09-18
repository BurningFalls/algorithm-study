#include <iostream>
#include <string.h>
using namespace std;

int main() {
	string S;
	string cr[8] = { "c=", "c-", "d-", "lj", "nj", "s=", "z=", "dz=" };
	cin >> S;
	int len = S.size();
	string temp_s;
	int count = 0;
	int i = 0;
	bool flag = false;

	while (i < len) {
		if (strcmp(S.substr(i, 3).c_str(), cr[7].c_str()) == 0) {
			i += 2;
			count++;
			flag = true;
		}
		else {
			for (int j = 0; j < 7; j++) {
				if (strcmp(S.substr(i, 2).c_str(), cr[j].c_str()) == 0) {
					i++;
					count++;
					flag = true;
					break;
				}
			}
		}
		if (flag == false) {
			count++;
		}
		flag = false;
		i++;
	}
	cout << count << endl;

	return 0;
}