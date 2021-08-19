#include <bits/stdc++.h>
using namespace std;

int wh[200001];

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		string s;
		int wh_max = 1;
		int idx = 0;
		vector<int> zero_v, one_v;
		cin >> n;
		cin >> s;

		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (one_v.empty()) {
					idx++;
					zero_v.push_back(idx);
					wh[i] = idx;
				}
				else {
					zero_v.push_back(one_v.back());
					wh[i] = one_v.back();
					one_v.pop_back();
				}
			}
			else if (s[i] == '1') {
				if (zero_v.empty()) {
					idx++;
					one_v.push_back(idx);
					wh[i] = idx;
				}
				else {
					one_v.push_back(zero_v.back());
					wh[i] = zero_v.back();
					zero_v.pop_back();
				}
			}
			wh_max = max(wh_max, wh[i]);
		}
		cout << wh_max << "\n";
		for (int i = 0; i < n; i++)
			cout << wh[i] << " ";
		cout << "\n";
	}

	return 0;
}