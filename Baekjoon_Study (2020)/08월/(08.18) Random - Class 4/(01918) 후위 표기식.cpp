#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	string s;
	int len;
	vector<char> v;
	string ans = "";
	cin >> s;
	len = s.size();
	FOR(i, 0, len - 1) {
		if (s[i] >= int('A') && s[i] <= int('Z')) {
			ans += s[i];
		}
		else {
			if (s[i] == '+' || s[i] == '-') {
				while (!v.empty() && v.back() != '(') {
					ans += v.back();
					v.pop_back();
				}
				v.push_back(s[i]);
			}
			else if (s[i] == '*' || s[i] == '/') {
				while (!v.empty() && (v.back() == '*' || v.back() == '/')) {
					ans += v.back();
					v.pop_back();
				}
				v.push_back(s[i]);
			}
			else if (s[i] == '(') {
				v.push_back(s[i]);
			}
			else if (s[i] == ')') {
				while (!v.empty() && v.back() != '(') {
					ans += v.back();
					v.pop_back();
				}
				v.pop_back();
			}
		}
	}
	while (!v.empty()) {
		ans += v.back();
		v.pop_back();
	}
	cout << ans;

	return 0;
}