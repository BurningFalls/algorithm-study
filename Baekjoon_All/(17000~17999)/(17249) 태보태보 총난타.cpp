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
	cin >> s;
	int len = s.size();
	bool flag = false;
	int left = 0, right = 0;
	FOR(i, 0, len - 1) {
		if (!flag && s[i] == '@')
			left++;
		else if (flag && s[i] == '@')
			right++;
		if (s[i] == '(')
			flag = true;
	}
	cout << left << " " << right;

	return 0;
}