#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int M;
int cnt[1001] = { 0, };

void Calc(string s) {
	if (s == "0") {
		cnt[0] += 1;
		return;
	}
	int len = s.size();
	string sub = "";
	FOR(i, 2, len - 1)
		sub += s[i];
	int up = stoi(sub);
	up *= pow(10, 8 - len) * M;
	up /= pow(10, 6);
	cnt[up] += 1;
}

int main() {
	FASTIO;
	cin >> M;
	string s;
	cin.ignore();
	getline(cin, s);
	s += ' ';
	int len = s.size();
	string sub = "";
	FOR(i, 0, len - 1) {
		if (s[i] == ' ') {
			Calc(sub);
			sub = "";
		}
		else
			sub += s[i];
	}
	FOR(i, 0, M - 1)
		cout << cnt[i] << " ";


	return 0;
}