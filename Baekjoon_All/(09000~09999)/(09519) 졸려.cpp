#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	int X;
	string s;
	cin >> X;
	cin >> s;
	int len = LEN(s);
	vector<char> v(len);
	FOR(i, 0, LEN(s) - 1) {
		v[i] = s[i];
	}
	char x = v[1];
	int cnt = 0;
	while (true) {
		vector<char> ch;
		for (int i = 0; i < len; i += 2) {
			ch.push_back(v[i]);
		}
		for (int i = (len % 2 == 0 ? len - 1 : len - 2); i >= 0; i -= 2) {
			ch.push_back(v[i]);
		}

		FOR(i, 0, len - 1) {
			v[i] = ch[i];
		}
		cnt++;
		bool flag = true;
		FOR(i, 0, len - 1) {
			if (v[i] != s[i]) {
				flag = false;
				break;
			}
		}
		if (flag) break;
	}
	X %= cnt;

	FOR(i, 0, LEN(s) - 1) {
		v[i] = s[i];
	}
	while (X--) {
		vector<char> ch;
		for (int i = 0; i < len; i += 2) {
			ch.push_back(v[i]);
		}
		for (int i = (len % 2 == 0 ? len - 1 : len - 2); i >= 0; i -= 2) {
			ch.push_back(v[i]);
		}

		FOR(i, 0, len - 1) {
			v[i] = ch[i];
		}
	}
	FOR(i, 0, len - 1) {
		cout << v[i];
	}

	return 0;
}