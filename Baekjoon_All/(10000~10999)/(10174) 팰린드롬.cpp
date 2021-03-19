#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool is_Same(char x, char y) {
	int flag1 = 0, flag2 = 0;
	if (x >= 'A' && x <= 'Z')
		flag1 = 1;
	else if (x >= 'a' && x <= 'z')
		flag1 = 2;
	else
		flag1 = 3;
	if (y >= 'A' && y <= 'Z')
		flag2 = 1;
	else if (y >= 'a' && y <= 'z')
		flag2 = 2;
	else
		flag2 = 3;
	if (flag1 == flag2) {
		return (x == y);
	}
	else {
		if (flag1 == 1 && flag2 == 2) {
			return (x - 'A' + 'a' == y);
		}
		else if (flag1 == 2 && flag2 == 1) {
			return (x - 'a' + 'A' == y);
		}
		else
			return false;
	}
}

bool Check(string s) {
	int len = s.size();
	FOR(i, 0, len / 2 - 1) {
		char x = s[i];
		char y = s[len - 1 - i];
		bool flag = is_Same(x, y);
		if (!flag)
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	int N;
	string s;
	cin >> N;
	cin.ignore();
	FOR(i, 1, N) {
		getline(cin, s);
		if (Check(s))
			cout << "Yes";
		else
			cout << "No";
		cout << "\n";
	}


	return 0;
}