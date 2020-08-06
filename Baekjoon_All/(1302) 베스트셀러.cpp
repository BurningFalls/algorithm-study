#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	string str;
	vector<pair<string, int>> v;
	bool flag;
	string max_str;
	int max_num = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		flag = false;
		for (int j = 0; j < v.size(); j++) {
			if (v[j].first == str) {
				v[j].second++;
				flag = true;
				break;
			}
		}
		if (flag == false) {
			v.push_back(make_pair(str, 1));
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (max_num < v[i].second) {
			max_num = v[i].second;
			max_str = v[i].first;
		}
		if (max_num == v[i].second) {
			max_str = min(v[i].first, max_str);
		}
	}
	cout << max_str;

	return 0;
}