#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int cnt[4] = { 0, };
	string s;
	cin >> s;
	int len = s.size();
	bool flag = true;
	FOR(i, 0, len - 1) {
		if (s[i] == '2')
			cnt[0]++;
		else if (s[i] == '0')
			cnt[1]++;
		else if (s[i] == '1')
			cnt[2]++;
		else if (s[i] == '8')
			cnt[3]++;
		else
			flag = false;
	}
	if (!flag)
		cout << 0;
	else {
		if (cnt[0] != 0 && cnt[1] != 0 && cnt[2] != 0 && cnt[3] != 0) {
			if (cnt[0] == cnt[1] && cnt[1] == cnt[2] && cnt[2] == cnt[3]) {
				cout << 8;
			}
			else {
				cout << 2;
			}
		}
		else {
			cout << 1;
		}
	}


	return 0;
}