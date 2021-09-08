#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

bool is_one[51];
char ans[51][51];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		MEMSET(is_one, 0);
		int N;
		cin >> N;
		string s;
		cin >> s;
		int one_cnt = 0;
		int two_cnt = 0;
		FOR(i, 0, N - 1) {
			if (s[i] == '1') {
				one_cnt++;
				is_one[i + 1] = 1;
			}
			else if (s[i] == '2')
				two_cnt++;
		}
		if (one_cnt == N) {
			cout << "YES\n";
			FOR(i, 1, N) {
				FOR(j, 1, N) {
					if (i == j)
						cout << 'X';
					else
						cout << '=';
				}
				cout << "\n";
			}
		}
		else if (two_cnt >= 3) {
			cout << "YES\n";
			bool flag = true;
			FOR(i, 1, N) {
				FOR(j, 1, N) {
					if (i == j)
						ans[i][j] = 'X';
					else if (is_one[i] || is_one[j])
						ans[i][j] = '=';
					else if (i < j) {
						ans[i][j] = (flag ? '+' : '-');
						flag = !flag;
					}
					else if (i > j)
						ans[i][j] = ((ans[j][i] == '+') ? '-' : '+');
				}
			}
			FOR(i, 1, N) {
				FOR(j, 1, N) {
					cout << ans[i][j];
				}
				cout << "\n";
			}
		}
		else {
			cout << "NO\n";
		}
	}



	return 0;
}