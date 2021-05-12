#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool possi[9][9] = { 0, };

bool Check(string s) {
	int len = s.size();
	if (s[0] != '1')
		return false;
	if (s[len - 1] != '2')
		return false;
	FOR(i, 0, len - 2) {
		int x = s[i] - '0';
		int y = s[i + 1] - '0';
		if (!possi[x][y])
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	possi[1][4] = 1;
	possi[1][5] = 1;
	possi[3][4] = 1;
	possi[3][5] = 1;
	possi[4][2] = 1;
	possi[4][3] = 1;
	possi[5][8] = 1;
	possi[6][2] = 1;
	possi[6][3] = 1;
	possi[7][8] = 1;
	possi[8][6] = 1;
	possi[8][7] = 1;
	int idx = 1;
	while (true) {
		string s;
		cin >> s;
		if (s == "0")
			break;
		cout << idx << ". ";
		cout << (Check(s) ? "VALID" : "NOT") << "\n";
		idx++;
	}


	return 0;
}