#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string S, T;
bool flag = false;
int Slen;

void Func(string s) {
	string tmp;
	int len = s.size();
	if (s == S) {
		flag = true;
		return;
	}
	if (len == Slen)
		return;
	if (s[0] == 'B') {
		tmp = s;
		reverse(tmp.begin(), tmp.end());
		tmp.pop_back();
		Func(tmp);
	}
	if (s[len - 1] == 'A') {
		tmp = s;
		tmp.pop_back();
		Func(tmp);
	}
}

int main() {
	FASTIO;
	cin >> S >> T;
	Slen = S.size();
	Func(T);
	cout << flag;

	return 0;
}