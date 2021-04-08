#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	while (true) {
		string s;
		cin >> s;
		if (s == "*")
			break;
		int len = s.size();
		bool flag = true;
		FOR(i, 1, len - 1) {
			set<string> S;
			FOR(start, 0, len - i - 1) {
				int end = start + i;
				string tmp = "";
				tmp += s[start];
				tmp += s[end];
				if (S.count(tmp)) {
					flag = false;
					break;
				}
				S.insert(tmp);
			}
			if (!flag)
				break;
		}
		cout << s << " is ";
		if (!flag)
			cout << "NOT ";
		cout << "surprising.\n";
	}


	return 0;
}