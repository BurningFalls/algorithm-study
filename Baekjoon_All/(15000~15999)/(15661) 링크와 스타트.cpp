#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int N;
int S[21][21];
bool team[21];
int ans = INF;

int Calc() {
	vector<int> team1, team2;
	FOR(i, 0, N - 1) {
		if (team[i] == 0)
			team1.push_back(i + 1);
		else if (team[i] == 1)
			team2.push_back(i + 1);
	}
	int len1 = team1.size();
	int len2 = team2.size();
	if (len1 == 0 || len2 == 0)
		return INF;
	int score1 = 0, score2 = 0;
	FOR(i, 0, len1 - 1) {
		FOR(j, i + 1, len1 - 1) {
			score1 += S[team1[i]][team1[j]];
			score1 += S[team1[j]][team1[i]];
		}
	}
	FOR(i, 0, len2 - 1) {
		FOR(j, i + 1, len2 - 1) {
			score2 += S[team2[i]][team2[j]];
			score2 += S[team2[j]][team2[i]];
		}
	}
	return abs(score1 - score2);
}

void Team(int cnt) {
	if (cnt == N) {
		ans = min(ans, Calc());
		return;
	}
	FOR(i, 0, 1) {
		team[cnt] = i;
		Team(cnt + 1);
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> S[i][j];
		}
	}
	Team(0);
	cout << ans;

	return 0;
}