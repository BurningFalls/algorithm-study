#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s1, s2;
	int sum;
	string result;
	int len;
	int flag = true;
	cin >> s1 >> s2;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	sum = atoi(s1.c_str()) + atoi(s2.c_str());
	result = to_string(sum);
	reverse(result.begin(), result.end());
	len = result.size();
	for (int i = 0; i < len; i++) {
		if (result[i] != '0' || flag == false) {
			cout << result[i];
			flag = false;
		}
		else if (result[i] == '0' && flag == true) {
			continue;
		}
	}

	return 0;
}