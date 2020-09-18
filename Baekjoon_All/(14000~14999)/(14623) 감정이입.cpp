#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

string Sum(string s1, string s2) {
	string s3 = "", ans = "";
	int temp = max(s1.size(), s2.size()) - min(s1.size(), s2.size());
	bool flag = 0;
	FOR(i, 1, temp)
		s3 += "0";
	if (s1.size() >= s2.size()) {
		s3 += s2;
		ROF(i, s1.size() - 1, 0) {
			int t = (s1[i] - '0') + (s3[i] - '0') + flag;
			if (t == 0) {
				ans += '0';
				flag = 0;
			}
			else if (t == 1) {
				ans += '1';
				flag = 0;
			}
			else if (t == 2) {
				ans += '0';
				flag = 1;
			}
			else if (t == 3) {
				ans += '1';
				flag = 1;
			}
		}
		if (flag)
			ans += '1';
	}
	else if (s1.size() < s2.size()) {
		s3 += s1;
		ROF(i, s2.size() - 1, 0) {
			int t = (s2[i] - '0') + (s3[i] - '0') + flag;
			if (t == 0) {
				ans += '0';
				flag = 0;
			}
			else if (t == 1) {
				ans += '1';
				flag = 0;
			}
			else if (t == 2) {
				ans += '0';
				flag = 1;
			}
			else if (t == 3) {
				ans += '1';
				flag = 1;
			}
		}
		if (flag)
			ans += '1';
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	string s1, s2, a = "0";
	cin >> s1 >> s2;
	if (s1.size() < s2.size()) {
		string temp;
		temp = s1;
		s1 = s2;
		s2 = temp;
	}
	int len = s2.size();
	ROF(i, len - 1, 0) {
		if (s2[i] == '1') {
			string s = s1;
			FOR(j, 1, len - i - 1)
				s += '0';
			a = Sum(a, s);
		}
	}
	cout << a;

	return 0;
}