#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	string str;
	bool zero_flag = false;
	int sum = 0;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if ((str[i] - '0' == 0) && zero_flag == false)
			zero_flag = true;
		sum += (str[i] - '0');
	}
	if (zero_flag == false || sum % 3 != 0) {
		cout << -1;
	}
	else {
		sort(str.begin(), str.end(), compare);
		cout << str;
	}

	return 0;
}