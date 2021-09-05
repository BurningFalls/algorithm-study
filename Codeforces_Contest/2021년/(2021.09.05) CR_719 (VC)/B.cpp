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
		string s = to_string(N);
		int ans = (LEN(s) - 1) * 9;
		int num = s[0] - '0';
		ans += num;
		string tmp = "";
		FOR(i, 1, LEN(s))
			tmp += s[0];
		int ntmp = stoi(tmp);
		if (N < ntmp)
			ans--;
		cout << ans << "\n";
	}



	return 0;
}