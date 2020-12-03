#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string s;
	cin >> s;
	int len = s.size();
	int zero_cnt = 0;
	int one_cnt = 0;
	if (len == 1)
		cout << 0;
	else {
		FOR(i, 0, len - 2) {
			if (s[i] == '0' && s[i + 1] == '1')
				zero_cnt++;
			else if (s[i] == '1' && s[i + 1] == '0')
				one_cnt++;
		}
		if (s[len - 1] == '0')
			zero_cnt++;
		else if (s[len - 1] == '1')
			one_cnt++;
		cout << min(zero_cnt, one_cnt);
	}

	return 0;
}