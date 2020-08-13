#include <bits/stdc++.h>
using namespace std;

int Ch(string s, int st) {
	char x = st + int('a');
	if (s.size() == 1) {
		if (s[0] == x)
			return 0;
		else
			return 1;
	}
	int len = s.size() / 2;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] != x)
			cnt1++;
	}
	for (int i = len; i < len * 2; i++) {
		if (s[i] != x)
			cnt2++;
	}
	return min(cnt1 + Ch(s.substr(len, len), st + 1), cnt2 + Ch(s.substr(0, len), st + 1));
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		string s;
		cin >> n;
		cin >> s;
		cout << Ch(s, 0) << "\n";
	}

	return 0;
}