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
		int N;
		cin >> N;
		string s;
		cin >> s;
		bool flag = false;
		FOR(i, 0, N - 2) {
			if (s[i] == 'a' && s[i + 1] == 'b') {
				cout << i + 1 << " " << i + 2 << "\n";
				flag = true;
				break;
			}
			else if (s[i] == 'b' && s[i + 1] == 'a') {
				cout << i + 1 << " " << i + 2 << "\n";
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << -1 << " " << -1 << "\n";
	}


	return 0;
}