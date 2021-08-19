#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

char arr[300002];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		string s;
		bool flag = true;
		cin >> n >> k;
		cin >> s;
		FOR(i, 0, n - 1)
			arr[i] = '.';
		FOR(i, 0, n - 1) {
			if (s[i] == '?') continue;
			if (arr[i % k] == '.') {
				arr[i % k] = s[i];
			}
			else if (arr[i % k] != '.') {
				if (arr[i % k] != s[i]) {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			int zero_cnt = 0;
			int one_cnt = 0;
			FOR(i, 0, k - 1) {
				if (arr[i] == '1')
					one_cnt++;
				else if (arr[i] == '0')
					zero_cnt++;
			}
			if (one_cnt > k / 2 || zero_cnt > k / 2)
				flag = false;
		}
		if (flag)
			cout << "YES";
		else
			cout << "NO";
		cout << "\n";
	}

	return 0;
}