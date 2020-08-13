#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string str;
	vector<int> v;
	bool flag = true;
	int temp = 1;
	int answer = 0;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			temp *= 2;
			v.push_back(1);
		}
		else if (str[i] == ')') {
			if (v.empty() || v.back() != 1) {
				flag = false;
				break;
			}
			else {
				if (str[i - 1] == '(') {
					answer += temp;
				}
				temp /= 2;
				v.pop_back();
			}
		}
		else if (str[i] == '[') {
			temp *= 3;
			v.push_back(2);
		}
		else if (str[i] == ']') {
			if (v.empty() || v.back() != 2) {
				flag = false;
				break;
			}
			else {
				if (str[i - 1] == '[') {
					answer += temp;
				}
				temp /= 3;
				v.pop_back();
			}
		}
	}
	if (!flag || !v.empty())
		cout << 0;
	else
		cout << answer;

	return 0;
}