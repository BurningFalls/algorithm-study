#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int Calc(int x, int y, char oper) {
	if (oper == '+')
		return x + y;
	else if (oper == '-')
		return x - y;
	else if (oper == '*')
		return x * y;
	else if (oper == '/')
		return x / y;
}

int main() {
	FASTIO;
	string s;
	cin >> s;
	int len = s.size();
	vector<int> v;
	FOR(i, 0, len - 1) {
		if (s[i] >= '0' && s[i] <= '9') {
			v.push_back(s[i] - '0');
		}
		else {
			int a = v.back();
			v.pop_back();
			int b = v.back();
			v.pop_back();
			int result = Calc(b, a, s[i]);
			v.push_back(result);
		}
	}
	cout << v[0];

	return 0;
}