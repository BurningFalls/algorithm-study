#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int len = s.size();
		deque<char> dq1, dq2;
		FOR(i, 0, len - 1) {
			if (s[i] == '<') {
				if (dq1.empty()) continue;
				dq2.push_front(dq1.back());
				dq1.pop_back();
			}
			else if (s[i] == '>') {
				if (dq2.empty()) continue;
				dq1.push_back(dq2.front());
				dq2.pop_front();
			}
			else if (s[i] == '-') {
				if (dq1.empty()) continue;
				dq1.pop_back();
			}
			else {
				dq1.push_back(s[i]);
			}
		}
		int len1 = dq1.size();
		int len2 = dq2.size();
		FOR(i, 0, len1 - 1)
			cout << dq1[i];
		FOR(i, 0, len2 - 1)
			cout << dq2[i];
		cout << "\n";
	}

	return 0;
}