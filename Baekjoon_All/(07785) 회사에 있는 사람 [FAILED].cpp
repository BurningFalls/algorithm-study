#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	return a > b;
}

int main() {
	int N;
	string name, state;
	vector<pair<string, int>> v;
	vector<string> ans_v;
	int len;
	bool flag;
	int node;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name >> state;
		len = v.size();
		flag = false;
		for (int j = 0; j < len; j++) {
			if (name == v[j].first) {
				flag = true;
				node = j;
				break;
			}
		}
		if (flag) {
			v[node].second -= 1;
		}
		else if (!flag) {
			v.push_back(make_pair(name, 1));
		}
	}
	len = v.size();
	for (int i = 0; i < len; i++) {
		if (v[i].second == 1)
			ans_v.push_back(v[i].first);
	}
	sort(ans_v.begin(), ans_v.end(), compare);
	len = ans_v.size();
	for (int i = 0; i < len; i++) {
		cout << ans_v[i] << "\n";
	}

	return 0;
}