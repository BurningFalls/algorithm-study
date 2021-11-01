#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int main() {
	FASTIO;
	string s[5];
	char tmp1[5] = { '.', 'o', 'm', 'l', 'n' };
	char tmp2[5] = { 'o', 'w', 'l', 'n', '.' };
	FOR(i, 0, 4) {
		cin >> s[i];
	}
	FOR(j, 0, LEN(s[0]) - 1) {
		bool flag1 = false;
		bool flag2 = false;
		bool flag3 = false;
		FOR(i, 0, 4) {
			if (s[i][j] == 'm') {
				flag1 = true;
			}
			else if (s[i][j] == 'w') {
				flag2 = true;
			}
			else if (s[i][j] == 'L') {
				flag3 = true;
			}
		}
		if (flag3) continue;
		if (flag1) {
			FOR(i, 0, 4) {
				FOR(k, 0, 4) {
					if (tmp1[k] == s[i][j]) {
						s[i][j] = tmp2[k];
						break;
					}
				}
			}
		}
		else if (flag2) {
			FOR(i, 0, 4) {
				FOR(k, 0, 4) {
					if (tmp2[k] == s[i][j]) {
						s[i][j] = tmp1[k];
						break;
					}
				}
			}
		}
	}
	FOR(i, 0, 4) {
		cout << s[i] << "\n";
	}

	return 0;
}