#include <bits/stdc++.h>
using namespace std;

int cnt;

bool Check(string s, int a, int b) {
	int len = s.size();
	bool a_flag = false;
	bool b_flag = false;
	for (int i = 0; i < len; i++) {
		if (s[i] - '0' == a) {
			if (a_flag == false) {
				a_flag = true;
				b_flag = false;
				cnt++;
			}
		}
		else if (s[i] - '0' == b) {
			if (b_flag == false) {
				b_flag = true;
				a_flag = false;
				cnt++;
			}
		}
	}
	if (cnt % 2 == 1)
		cnt -= 1;
	return true;
}

int main() {
	int T;
	string s;
	int len;
	int ans;
	int one_max;
	vector<pair<int, int>> v;
	for (int i = 0; i < 10; i++)
		v.push_back(make_pair(0, i));
	cin >> T;
	for (int t = 0; t < T; t++) {
		for (int i = 0; i < 10; i++)
			v[i].first = 0;
		cin >> s;
		ans = 0;
		one_max = 0;
		len = s.size();
		for (int i = 0; i < len; i++)
			v[s[i] - '0'].first++;
		for (int i = 0; i < 10; i++) {
			if (one_max < v[i].first)
				one_max = v[i].first;
		}
		for (int i = 0; i <= 8; i++) {
			for (int j = i + 1; j <= 9; j++) {
				cnt = 0;
				if (!Check(s, i, j)) continue;
				ans = max(ans, cnt);
			}
		}
		ans = max(ans, one_max);
		cout << len - ans << "\n";
	}

	return 0;
}