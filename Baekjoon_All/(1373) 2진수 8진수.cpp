#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int arr[3] = { 0, };
	int len;
	int temp;
	cin >> str;
	len = str.size();
	temp = len % 3;
	if (temp == 1) {
		cout << str[0];
	}
	else if (temp == 2) {
		cout << int(str[0] - '0') * 2 + int(str[1] - '0');
	}
	for (int i = temp; i < str.size(); i += 3) {
		arr[0] = str[i] - '0';
		arr[1] = str[i + 1] - '0';
		arr[2] = str[i + 2] - '0';
		cout << 4 * arr[0] + 2 * arr[1] + arr[2];
	}

	return 0;
}