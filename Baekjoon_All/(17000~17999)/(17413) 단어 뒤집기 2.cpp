#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string s;
	getline(cin, s);
	s += ' ';
	int len = s.size();
	string temp = "";
	bool flag = false;
	FOR(i, 0, len - 1) {
		if (s[i] == ' ') {
			int len_temp = temp.size();
			if (flag) {
				FOR(j, 0, len_temp - 1)
					cout << temp[j];
			}
			else if (!flag) {
				ROF(j, len_temp - 1, 0)
					cout << temp[j];
			}
			if (i != len - 1)
				cout << " ";
			temp = "";
		}
		else if (s[i] == '<') {
			int len_temp = temp.size();
			ROF(j, len_temp - 1, 0)
				cout << temp[j];
			cout << "<";
			temp = "";
			flag = true;
		}
		else if (s[i] == '>') {
			int len_temp = temp.size();
			FOR(j, 0, len_temp - 1)
				cout << temp[j];
			cout << ">";
			temp = "";
			flag = false;
		}
		else {
			temp += s[i];
		}
	}

	return 0;
}