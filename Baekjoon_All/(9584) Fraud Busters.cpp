#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string ori_str;
	int N;
	string sub_str;
	vector<string> ans;
	bool flag;
	cin >> ori_str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		flag = true;
		cin >> sub_str;
		for (int i = 0; i < ori_str.size(); i++) {
			if (ori_str[i] == '*') continue;
			if (ori_str[i] != sub_str[i]) {
				flag = false;
				break;
			}
		}
		if (flag)
			ans.push_back(sub_str);
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}