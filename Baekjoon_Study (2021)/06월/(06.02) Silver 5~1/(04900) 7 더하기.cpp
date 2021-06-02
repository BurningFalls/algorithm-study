#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string seg[10] = { "063", "010", "093", "079", "106", 
	"103", "119", "011", "127", "107" };
	string str;
	while (true) {
		cin >> str;
		if (str == "BYE")
			break;
		int len = str.size();
		string s1 = "", s2 = "";
		bool flag = false;
		FOR(i, 0, len - 1) {
			if (str[i] == '+') {
				flag = true;
				continue;
			}
			if (str[i] == '=')
				continue;
			if (!flag)
				s1 += str[i];
			else if (flag)
				s2 += str[i];
		}
		string num1 = "", num2 = "";
		int len_s1 = s1.size();
		int len_s2 = s2.size();
		string tmp = "";
		FOR(i, 0, len_s1 - 1) {
			tmp += s1[i];
			if (i % 3 == 2) {
				FOR(j, 0, 9) {
					if (seg[j] == tmp) {
						num1 += (j + '0');
						break;
					}
				}
				tmp = "";
			}
		}
		tmp = "";
		FOR(i, 0, len_s2 - 1) {
			tmp += s2[i];
			if (i % 3 == 2) {
				FOR(j, 0, 9) {
					if (seg[j] == tmp) {
						num2 += (j + '0');
						break;
					}
				}
				tmp = "";
			}
		}
		int result = stoi(num1) + stoi(num2);
		tmp = to_string(result);
		int tmp_len = tmp.size();
		string ans = "";
		FOR(i, 0, tmp_len - 1) {
			ans += seg[tmp[i] - '0'];
		}
		cout << s1 << "+" << s2 << "=" << ans << "\n";
	}



	return 0;
}