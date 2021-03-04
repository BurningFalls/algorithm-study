#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

set<string> Set;

int main() {
	FASTIO;
	string s;
	cin >> s;
	int len = s.size();
	FOR(i, 0, len - 1) {
		string tmp = "";
		FOR(j, i, len - 1) {
			tmp += s[j];
			Set.insert(tmp);
		}
	}
	int siz = Set.size();
	cout << siz;

	return 0;
}