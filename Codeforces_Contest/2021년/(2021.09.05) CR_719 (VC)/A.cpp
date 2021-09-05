#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		bool check[26] = { 0, };
		int N;
		string s;
		cin >> N;
		cin >> s;
		string ss = "";
		char prev = 'a';
		FOR(i, 0, N - 1) {
			if (prev != s[i])
				ss += s[i];
			prev = s[i];
		}
		bool flag = true;
		FOR(i, 0, LEN(ss) - 1) {
			if (check[ss[i] - 'A']) {
				flag = false;
				break;
			}
			check[ss[i] - 'A'] = 1;
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}


	return 0;
}