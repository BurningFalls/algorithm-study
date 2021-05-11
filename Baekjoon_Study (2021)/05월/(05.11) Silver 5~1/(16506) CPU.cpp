#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string arr[24] = { "ADD", "ADDC", "SUB", "SUBC", "MOV", "MOVC", "AND", "ANDC",
	"OR", "ORC", "NOT", "MULT", "MULTC", "LSFTL", "LSFTLC", "LSFTR", "LSFTRC",
	"ASFTR", "ASFTRC", "RL", "RLC", "RR", "RRC" };
string num[24] = { "00000", "00001", "00010", "00011", "00100", "00101", "00110", "00111",
"01000", "01001", "01010", "01100", "01101", "01110", "01111", "10000", "10001", "10010", "10011",
"10100", "10101", "10110", "10111" };

string CH(int x, int max) {
	string tmp = "";
	if (x == 0) {
		tmp += '0';
	}
	while (x != 0) {
		tmp += x % 2 + '0';
		x /= 2;
	}
	int len = tmp.size();
	if (len < max) {
		FOR(i, 1, max - len) {
			tmp += '0';
		}
	}
	reverse(tmp.begin(), tmp.end());
	return tmp;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		string ans = "";
		string s;
		int a, b, c;
		cin >> s >> a >> b >> c;
		FOR(j, 0, 23) {
			if (arr[j] == s) {
				ans += num[j];
			}
		}
		ans += '0';
		ans += CH(a, 3);
		ans += CH(b, 3);
		if (ans[4] == '0') {
			ans += CH(c, 3);
			ans += '0';
		}
		else if (ans[4] == '1') {
			ans += CH(c, 4);
		}
		cout << ans << "\n";
	}


	return 0;
}