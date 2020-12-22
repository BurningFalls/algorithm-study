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
	int upper_cnt = 0;
	int none_cnt = 0;
	int ub_cnt = 0;
	cin >> s;
	FOR(i, 0, s.size() - 1) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			upper_cnt++;
		else if (s[i] == '_')
			ub_cnt++;
	}
	if (!(s[0] >= 'a' && s[0] <= 'z')) {
		cout << "Error!";
		return 0;
	}
	if (upper_cnt == 0) {
		vector<char> v;
		bool flag = true;
		int idx = 1;
		int len = s.size();
		v.push_back(s[0]);
		while (idx <= len - 1) {
			if (s[idx] == '_') {
				if (idx == len - 1) {
					flag = false;
					break;
				}
				else {
					idx++;
					if (s[idx] == '_') {
						flag = false;
						break;
					}
					else {
						int x = s[idx] - 'a';
						char y = x + 'A';
						v.push_back(y);
						idx++;
					}
				}
			}
			else {
				v.push_back(s[idx]);
				idx++;
			}
		}
		if (flag) {
			FOR(i, 0, v.size() - 1)
				cout << v[i];
		}
		else {
			cout << "Error!";
			return 0;
		}
	}
	else {
		if (ub_cnt != 0) {
			cout << "Error!";
			return 0;
		}
		cout << s[0];
		FOR(i, 1, s.size() - 1) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				cout << "_";
				int x = s[i] - 'A';
				char y = x + 'a';
				cout << y;
			}
			else
				cout << s[i];
		}
	}

	return 0;
}