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
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		bool flag;
		int ans = INF;
		flag = false;
		vector<vector<char>> num = { {'5', '2'}, {'0', '5'}, {'5', '7'}, {'0', '0'} };
		FOR(n, 0, 3) {
			bool flag = false;
			int tmp = 0;
			ROF(i, LEN(s) - 1, 0) {
				if (!flag && s[i] == num[n][0]) {
					tmp = i;
					flag = true;
				}
				else if (flag && s[i] == num[n][1]) {
					int calc = (tmp - i - 1) + (LEN(s) - 1 - tmp);
					ans = min(ans, calc);
				}
			}
		}
		P1(ans);
	}


	return 0;
}