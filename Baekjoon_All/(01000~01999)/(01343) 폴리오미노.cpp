#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<char> v;

int main() {
	FASTIO;
	string s;
	cin >> s;
	s += '.';
	int cnt = 0;
	bool flag = true;
	FOR(i, 0, s.size() - 1) {
		if (s[i] == 'X') {
			cnt++;
		}
		else if (s[i] == '.') {
			if (cnt != 0) {
				if (cnt % 4 == 0) {
					FOR(j, 1, cnt)
						v.push_back('A');
				}
				else if (cnt % 2 == 0) {
					FOR(j, 1, cnt - 2)
						v.push_back('A');
					FOR(j, 1, 2)
						v.push_back('B');
				}
				else
					flag = false;
				cnt = 0;
			}
			if (i != s.size() - 1)
				v.push_back('.');
		}
	}
	if (!flag)
		cout << -1;
	else {
		FOR(i, 0, v.size() - 1)
			cout << v[i];
	}

	return 0;
}