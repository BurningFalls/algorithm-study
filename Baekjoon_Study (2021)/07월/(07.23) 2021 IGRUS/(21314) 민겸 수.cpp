#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string s;
int len;

string Change(string x) {
	int xlen = x.size();
	bool k_flag = false;
	int m_cnt = 0;
	FOR(i, 0, xlen - 1) {
		if (x[i] == 'K') {
			k_flag = true;
		}
		else if (x[i] == 'M') {
			m_cnt++;
		}
	}
	string ans = "";
	if (!k_flag) {
		ans += '1';
		FOR(i, 1, xlen - 1)
			ans += '0';
	}
	else if (k_flag) {
		ans += '5';
		FOR(i, 1, m_cnt) {
			ans += '0';
		}
	}
	return ans;
}

int main() {
	FASTIO;
	cin >> s;
	len = s.size();
	string ans1 = "", ans2 = "";
	string tmp = "";
	FOR(i, 0, len - 1) {
		tmp += s[i];
		if (s[i] == 'K') {
			string ch = Change(tmp);
			tmp = "";
			ans1 += ch;
		}
	}
	if (!tmp.empty()) {
		int tmp_len = tmp.size();
		FOR(i, 1, tmp_len)
			ans1 += '1';
	}
	tmp = "";
	FOR(i, 0, len - 1) {
		if (s[i] == 'K') {
			if (!tmp.empty()) {
				int tmp_len = tmp.size();
				ans2 += '1';
				FOR(i, 1, tmp_len - 1)
					ans2 += '0';
			}
			tmp = "";
			ans2 += '5';
		}
		else
			tmp += s[i];
	}
	if (!tmp.empty()) {
		int tmp_len = tmp.size();
		ans2 += '1';
		FOR(i, 1, tmp_len - 1)
			ans2 += '0';
	}
	cout << ans1 << "\n" << ans2;

	return 0;
}