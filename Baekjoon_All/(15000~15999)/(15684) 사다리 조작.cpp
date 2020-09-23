#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M, H;
bool ladder[31][11] = { 0, };
int Using;
int ans = -1;

bool Check() {
	FOR(i, 1, N) {
		int pos = i;
		FOR(j, 1, H) {
			if (ladder[j][pos])
				pos++;
			else if (ladder[j][pos - 1])
				pos--;
		}
		if (pos != i)
			return false;
	}
	return true;
}

void DFS(int y, int cnt) {
	if (cnt == Using) {
		if (Check()) {
			cout << Using;
			exit(0);
		}
		return;
	}
	FOR(i, y, H) {
		FOR(j, 1, N) {
			if (ladder[i][j - 1] || ladder[i][j] || ladder[i][j + 1]) continue;
			ladder[i][j] = 1;
			DFS(i, cnt + 1);
			ladder[i][j] = 0;
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M >> H;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1;
	}
	FOR(i, 0, 3) {
		Using = i;
		DFS(1, 0);
	}
	cout << -1;

	return 0;
}