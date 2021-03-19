#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool Check(string s) {
	int len = s.size();
	FOR(i, 0, len / 2 - 1) {
		if (s[i] != s[len - 1 - i])
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	string s;
	cin >> s;
	if (Check(s))
		cout << "true";
	else
		cout << "false";


	return 0;
}