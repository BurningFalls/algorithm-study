#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

bool Check(string s) {
	int len = s.size();
	int pos = 0;
	while (pos < len) {
		if (pos <= len - 2 && s[pos] == 'p' && s[pos + 1] == 'i')
			pos += 2;
		else if (pos <= len - 2 && s[pos] == 'k' && s[pos + 1] == 'a')
			pos += 2;
		else if (pos <= len - 3 && s[pos] == 'c' && s[pos + 1] == 'h' && s[pos + 2] == 'u')
			pos += 3;
		else
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	string s;
	cin >> s;
	if (Check(s))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}