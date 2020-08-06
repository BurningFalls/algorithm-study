#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<char> Left_v;
	vector<char> Right_v;
	string str;
	int M;
	char comm;
	char temp;
	int str_len;
	int left_len;
	int right_len;
	cin >> str;
	str_len = str.size();
	for (int i = 0; i < str_len; i++) {
		Left_v.push_back(str[i]);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> comm;
		left_len = Left_v.size();
		right_len = Right_v.size();
		if (comm == 'L') {
			if (left_len == 0) continue;
			Right_v.push_back(Left_v.back());
			Left_v.pop_back();
		}
		else if (comm == 'D') {
			if (right_len == 0) continue;
			Left_v.push_back(Right_v.back());
			Right_v.pop_back();
		}
		else if (comm == 'B') {
			if (left_len == 0) continue;
			Left_v.pop_back();
		}
		else if (comm == 'P') {
			cin >> temp;
			Left_v.push_back(temp);
		}
	}
	left_len = Left_v.size();
	right_len = Right_v.size();
	for (int i = 0; i < left_len; i++) {
		cout << Left_v[i];
	}
	for (int i = right_len - 1; i >= 0; i--) {
		cout << Right_v[i];
	}

	return 0;
}