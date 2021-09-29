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
		string s;
		cin >> s;
		int acnt = 0;
		int bcnt = 0;
		int ccnt = 0;
		FOR(i, 0, LEN(s) - 1) {
			if (s[i] == 'A')
				acnt++;
			else if (s[i] == 'B')
				bcnt++;
			else if (s[i] == 'C')
				ccnt++;
		}
		cout << (acnt + ccnt == bcnt ? "YES" : "NO") << "\n";
	}

	return 0;
}