#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int func(string a, string b) {
	if (LEN(a) > LEN(b))
		swap(a, b);
	ROF(len, LEN(a), 1) {
		FOR(start, 0, LEN(a) - len) {
			string sub = a.substr(start, len);
			if (b.find(sub) != string::npos) {
				return len;
			}
		}
	}
	return 0;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		string a, b;
		cin >> a >> b;
		int ans = func(a, b);
		cout << LEN(a) + LEN(b) - 2 * ans << "\n";
	}


	return 0;
}