#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

string c[10] = { "c'", "j'", "n'", "m'", "t'", "s'", "l'", "d'" };
char c2[7] = { 'a', 'e', 'i', 'o', 'u', 'h' };

int main() {
	FASTIO;
	string s;
	getline(cin, s);
	int ans;
	vector<string> v;
	string temp = "";
	FOR(i, 0, s.size() - 1) {
		if (s[i] == '-' || s[i] == ' ') {
			v.push_back(temp);
			temp = "";
		}
		else {
			temp += s[i];
		}
	}
	v.push_back(temp);
	ans = v.size();
	FOR(i, 0, v.size() - 1) {
		string temp = v[i];
		bool flag = false;
		bool flag2 = false;
		bool flag3 = false;
		bool flag4 = false;
		string x;
		if (temp.size() >= 3) {
			x = "";
			x += temp[0];
			x += temp[1];
			FOR(k, 0, 7) {
				if (x == c[k]) {
					flag = true;
					break;
				}
			}
			FOR(j, 0, 5) {
				if (temp[2] == c2[j]) {
					flag2 = true;
					break;
				}
			}
		}
		if (temp.size() >= 4) {
			x = "";
			x += temp[0];
			x += temp[1];
			x += temp[2];
			if (x == "qu'")
				flag3 = true;
			FOR(j, 0, 5) {
				if (temp[3] == c2[j]) {
					flag4 = true;
					break;
				}
			}
		}
		if ((flag && flag2) || (flag3 && flag4))
			ans++;
	}
	cout << ans;

	return 0;
}