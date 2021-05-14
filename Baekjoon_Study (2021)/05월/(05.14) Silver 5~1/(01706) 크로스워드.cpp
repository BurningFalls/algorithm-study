#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

set<string> se;

int main() {
	FASTIO;
	int R, C;
	char Map[22][22];
	cin >> R >> C;
	FOR(i, 1, C + 1)
		Map[R + 1][i] = '#';
	FOR(i, 1, R + 1)
		Map[i][C + 1] = '#';
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cin >> Map[i][j];
		}
	}
	FOR(i, 1, R + 1) {
		string tmp = "";
		FOR(j, 1, C + 1) {
			if (Map[i][j] == '#') {
				int len = tmp.size();
				if (len >= 2)
					se.insert(tmp);
				tmp = "";
			}
			else {
				tmp += Map[i][j];
			}
		}
	}
	FOR(i, 1, C + 1) {
		string tmp = "";
		FOR(j, 1, R + 1) {
			if (Map[j][i] == '#') {
				int len = tmp.size();
				if (len >= 2)
					se.insert(tmp);
				tmp = "";
			}
			else {
				tmp += Map[j][i];
			}
		}
	}
	auto it = se.begin();
	cout << (*it);

	return 0;
}