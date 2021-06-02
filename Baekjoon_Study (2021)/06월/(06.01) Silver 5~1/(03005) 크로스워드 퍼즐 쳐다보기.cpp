#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

set<string> SET;

int main() {
	FASTIO;
	int R, C;
	char Map[21][21];
	cin >> R >> C;
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cin >> Map[i][j];
		}
	}
	FOR(i, 1, R) {
		string tmp = "";
		FOR(j, 1, C) {
			if (Map[i][j] == '#') {
				int len = tmp.size();
				if (len >= 2)
					SET.insert(tmp);
				tmp = "";
			}
			else
				tmp += Map[i][j];
		}
		int len = tmp.size();
		if (len >= 2)
			SET.insert(tmp);
	}

	FOR(i, 1, C) {
		string tmp = "";
		FOR(j, 1, R) {
			if (Map[j][i] == '#') {
				int len = tmp.size();
				if (len >= 2)
					SET.insert(tmp);
				tmp = "";
			}
			else
				tmp += Map[j][i];
		}
		int len = tmp.size();
		if (len >= 2)
			SET.insert(tmp);
	}

	auto it = SET.begin();
	cout << (*it);

	return 0;
}