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
		string s;
		cin >> N;
		cin >> s;
		bool arr[4] = { 0, };
		char num[4] = { '2','0','2','0' };
		FOR(i, 0, 3) {
			if (s[i] == num[i])
				arr[i] = 1;
			else
				break;
		}
		ROF(i, 3, 0) {
			if (s[N - 4 + i] == num[i])
				arr[i] = 1;
			else
				break;
		}
		bool flag = true;
		FOR(i, 0, 3) {
			if (arr[i] == 0)
				flag = false;
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}

	return 0;
}