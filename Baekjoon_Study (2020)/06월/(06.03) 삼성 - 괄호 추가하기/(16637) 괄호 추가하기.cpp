#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
string equation;
bool bracket[9] = { 0, };
vector<int> numbers_v;
vector<char> opers_v;
long long int result_max;
bool flag = false;

int sub_Calculate(int node) {
	int num1, num2;
	char oper;
	num1 = equation[node] - '0';
	oper = equation[node + 1];
	num2 = equation[node + 2] - '0';
	switch (oper) {
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	}
	return 0;
}

void Divide() {
	int len;
	int i = 0;
	len = equation.size();
	numbers_v.clear();
	opers_v.clear();
	while (i < len) {
		if (i % 2 == 0) {
			if (i == len - 1 || bracket[i / 2] == 0) {
				numbers_v.push_back(equation[i] - '0');
				i++;
			}
			else if (bracket[i / 2] == 1) {
				numbers_v.push_back(sub_Calculate(i));
				i += 3;
			}
		}
		else if (i % 2 == 1) {
			opers_v.push_back(equation[i]);
			i++;
		}
	}
}

long long int Calculate() {
	long long int result;
	int len;
	result = numbers_v[0];
	len = opers_v.size();
	for (int i = 0; i < len; i++) {
		switch (opers_v[i]) {
		case '+':
			result += (long long int)(numbers_v[i + 1]);
			break;
		case '-':
			result -= (long long int)(numbers_v[i + 1]);
			break;
		case '*':
			result *= (long long int)(numbers_v[i + 1]);
			break;
		}
	}
	return result;
}

void Choose_Bracket(int cnt) {
	if (cnt == N / 2) {
		Divide();
		if (flag == false) {
			result_max = Calculate();
			flag = true;
		}
		else if (flag == true)
			result_max = max(result_max, Calculate());
		return;
	}

	for (int i = 0; i <= 1; i++) {
		if (cnt != 0 && bracket[cnt - 1] == 1 && i == 1) continue;
		bracket[cnt] = i;
		Choose_Bracket(cnt + 1);
	}
}

int main() {
	cin >> N;
	cin >> equation;

	Choose_Bracket(0);

	cout << result_max;

	return 0;
}