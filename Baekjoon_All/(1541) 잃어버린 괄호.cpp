#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	vector<int> numbers;
	vector<char> opers;
	string all_str;
	string num_str;
	string::iterator iter;
	int num;
	char oper;
	int temp;
	cin >> all_str;
	iter = all_str.begin();
	while (iter != all_str.end()) {
		num = 0;
		num_str = "";
		while (int(*iter) >= 48 && int(*iter) <= 57) {
			num_str += *iter;
			iter++;
			if (iter == all_str.end())
				break;
		}
		for (int i = 0; i < num_str.size(); i++) {
			temp = num_str[i] - '0';
			num += temp * pow(10, num_str.size() - 1 - i);
		}
		numbers.push_back(num);
		if (iter == all_str.end())
			break;
		oper = (*iter);
		opers.push_back(oper);
		iter++;
	}

	int answer;
	int sub_sum;
	int node = 0;
	answer = numbers[0];
	while (node < opers.size()) {
		if (opers[node] == '+') {
			answer += numbers[node + 1];
			node++;
		}
		else if (opers[node] == '-') {
			sub_sum = numbers[node + 1];
			node++;
			while (node < opers.size() && opers[node] == '+') {
				sub_sum += numbers[node + 1];
				node++;
			}
			answer -= sub_sum;
		}
	}
	cout << answer;

	return 0;
}