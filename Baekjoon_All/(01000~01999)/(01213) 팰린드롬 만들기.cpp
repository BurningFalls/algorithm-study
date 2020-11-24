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
	int cnt[26] = { 0, };
	cin >> s;
	int len = s.size();
	FOR(i, 0, len - 1)
		cnt[s[i] - 'A']++;
	int check = 0;
	char letter;
	FOR(i, 0, 25) {
		if (cnt[i] % 2 == 1) {
			check++;
			letter = i + 'A';
		}
	}
	if (len % 2 == 0) {
		if (check != 0)
			cout << "I'm Sorry Hansoo";
		else {
			FOR(i, 0, 25) {
				char x = i + 'A';
				FOR(j, 1, cnt[i] / 2)
					cout << x;
			}
			ROF(i, 25, 0) {
				char x = i + 'A';
				FOR(j, 1, cnt[i] / 2)
					cout << x;
			}
		}
	}
	else if (len % 2 == 1) {
		if (check != 1)
			cout << "I'm Sorry Hansoo";
		else {
			FOR(i, 0, 25) {
				char x = i + 'A';
				FOR(j, 1, cnt[i] / 2)
					cout << x;
			}
			cout << letter;
			ROF(i, 25, 0) {
				char x = i + 'A';
				FOR(j, 1, cnt[i] / 2)
					cout << x;
			}
		}
	}

	return 0;
}