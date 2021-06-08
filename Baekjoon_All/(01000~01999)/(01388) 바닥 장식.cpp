#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char Map[101][101];

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	int cnt = 0;
	bool flag;
	FOR(i, 1, N) {
		flag = false;
		FOR(j, 1, M) {
			if (Map[i][j] == '-') {
				if (!flag) {
					cnt++;
					flag = true;
				}
			}
			else
				flag = false;
		}
	}

	FOR(i, 1, M) {
		flag = false;
		FOR(j, 1, N) {
			if (Map[j][i] == '|') {
				if (!flag) {
					cnt++;
					flag = true;
				}
			}
			else
				flag = false;
		}
	}

	cout << cnt;


	return 0;
}