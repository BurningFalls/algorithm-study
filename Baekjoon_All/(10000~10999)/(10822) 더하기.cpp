#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	string str;
	int sum = 0;
	int temp;
	string sub_str;
	int start_node = 0;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ',') {
			sub_str = str.substr(start_node, i - start_node);
			temp = 0;
			for (int j = 0; j < sub_str.size(); j++) {
				temp += ((sub_str[j] - '0') * pow(10, sub_str.size() - j - 1));
			}
			sum += temp;
			start_node = i + 1;
		}
	}
	sub_str = str.substr(start_node, str.size() - start_node);
	temp = 0;
	for (int j = 0; j < sub_str.size(); j++) {
		temp += ((sub_str[j] - '0') * pow(10, sub_str.size() - j - 1));
	}
	sum += temp;
	cout << sum;

	return 0;
}