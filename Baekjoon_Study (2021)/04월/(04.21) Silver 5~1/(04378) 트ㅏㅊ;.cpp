#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char arr[5][15] = { {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='},
{'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'},
{'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', ' ', ' '},
{'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '\.', '/', ' ', ' ', ' '} };

int main() {
	FASTIO;
	string s;
	int len;
	while (getline(cin, s)) {
		len = s.size();
		FOR(k, 0, len - 1) {
			if (s[k] == ' ')
				cout << ' ';
			else {
				FOR(i, 0, 3) {
					FOR(j, 0, 12) {
						if (s[k] == arr[i][j]) {
							cout << arr[i][j - 1];
						}
					}
				}
			}
		}
		cout << "\n";
	}


	return 0;
}