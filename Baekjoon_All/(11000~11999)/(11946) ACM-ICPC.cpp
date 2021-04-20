#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

struct TEAM {
	int snum;
	int scnt;
	int ssum;
};

int N, M, Q;
int Time[101][16];
int Cnt[101][16] = { 0, };
TEAM Team[101];

bool cmp(TEAM a, TEAM b) {
	if (a.scnt == b.scnt) {
		if (a.ssum == b.ssum)
			return a.snum < b.snum;
		return a.ssum < b.ssum;
	}
	return a.scnt > b.scnt;
}

int main() {
	FASTIO;
	memset(Time, -1, sizeof(Time));
	cin >> N >> M >> Q;
	FOR(i, 1, Q) {
		int t, n, m;
		string result;
		cin >> t >> n >> m >> result;
		if (result == "AC") {
			if (Time[n][m] != -1) continue;
			Time[n][m] = t;
		} 
		else {
			if (Time[n][m] != -1) continue;
			Cnt[n][m] += 1;
		}
	}
	FOR(i, 1, N) {
		int cnt = 0;
		int sum = 0;
		FOR(j, 1, M) {
			if (Time[i][j] != -1) {
				sum += Time[i][j];
				cnt++;
				sum += Cnt[i][j] * 20;
			}
		}
		Team[i] = { i, cnt, sum };
	}

	sort(Team + 1, Team + N + 1, cmp);
	FOR(i, 1, N) {
		cout << Team[i].snum << " " << Team[i].scnt << " " << Team[i].ssum << "\n";
	}

	return 0;
}