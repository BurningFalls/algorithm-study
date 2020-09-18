#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

string Subtract(string s1, string s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	int flag = 0;
	string ans = "";
	ROF(i, len1 - 1, 0) {
		int temp = flag + int(s1[i] - '0') - int(s2[i] - '0');
		if (temp < 0) {
			flag = -1;
			ans += temp + 10 + '0';
		}
		else {
			flag = 0;
			ans += temp + '0';
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		string s1, s2;
		string ans = "";
		cin >> s1 >> s2;
		int len_s1 = s1.size();
		int len_s2 = s2.size();
		if (len_s1 < len_s2) {
			cout << 0 << "\n" << s1 << "\n\n";
			continue;
		}
		ROF(i, len_s1 - len_s2, 0) {
			string s3 = "";
			int cnt = 0;
			FOR(j, 1, len_s1 - len_s2 - i)
				s3 += '0';
			s3 += s2;
			FOR(j, 1, i)
				s3 += '0';
			while (s1 >= s3) {
				s1 = Subtract(s1, s3);
				cnt++;
			}
			ans += cnt + '0';
		}
		int zero_cnt = 0;
		bool flag = false;
		FOR(i, 0, ans.size() - 1) {
			if (!flag && ans[i] == '0')
				zero_cnt++;
			else {
				cout << ans[i];
				flag = true;
			}
		}
		if (zero_cnt == ans.size())
			cout << 0;
		cout << "\n";
		zero_cnt = 0;
		flag = false;
		FOR(i, 0, s1.size() - 1) {
			if (!flag && s1[i] == '0')
				zero_cnt++;
			else {
				cout << s1[i];
				flag = true;
			}
		}
		if (zero_cnt == s1.size())
			cout << 0;
		cout << "\n\n";
	}

	return 0;
}