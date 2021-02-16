#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>

set<string> s;

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		string sd;
		cin.ignore();
		getline(cin, sd);
		sd += ' ';
		int len = sd.size();
		string temp = "";
		FOR(i, 0, len - 1) {
			if (sd[i] == ' ') {
				s.insert(temp);
				temp = "";
			}
			else if (sd[i] != ' ') {
				temp += sd[i];
			}
		}
		string a, b, c;
		while (true) {
			cin >> a >> b >> c;
			if (a == "what" && b == "does" && c == "the")
				break;
			s.erase(c);
		}
		cin >> a >> b;
		FOR(i, 0, len - 1) {
			if (sd[i] == ' ') {
				if (s.count(temp))
					cout << temp << " ";
				temp = "";
			}
			else if (sd[i] != ' ') {
				temp += sd[i];
			}
		}
	}

	return 0;
}