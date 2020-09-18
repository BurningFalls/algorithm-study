#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	string imt1 = ":-)";
	string imt2 = ":-(";
	int hap_cnt = 0;
	int sad_cnt = 0;
	getline(cin, str);
	if (str.size() <= 2) {
		cout << "none";
	}
	else {
		for (int i = 0; i <= str.size() - 3; i++) {
			if (str[i] == ':' && str[i + 1] == '-') {
				if (str[i + 2] == ')') {
					hap_cnt++;
				}
				else if (str[i + 2] == '(') {
					sad_cnt++;
				}
			}
		}
		if (hap_cnt == 0 && sad_cnt == 0)
			cout << "none";
		else if (hap_cnt == sad_cnt)
			cout << "unsure";
		else if (hap_cnt > sad_cnt)
			cout << "happy";
		else if (hap_cnt < sad_cnt)
			cout << "sad";
	}

	return 0;
}