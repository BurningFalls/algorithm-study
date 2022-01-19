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

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
	int answer = 0;
	int N = LEN(board);
	int M = LEN(board[0]);
	vector<vector<int>> add(N + 1, vector<int>(M + 1, 0));
	FOR(i, 0, LEN(skill) - 1) {
		int type = skill[i][0];
		int r1 = skill[i][1];
		int c1 = skill[i][2];
		int r2 = skill[i][3];
		int c2 = skill[i][4];
		int degree = skill[i][5];
		if (type == 1) {
			degree *= (-1);
		}
		add[r1][c1] += degree;
		add[r1][c2 + 1] -= degree;
		add[r2 + 1][c1] -= degree;
		add[r2 + 1][c2 + 1] += degree;
	}
	FOR(i, 0, N) {
		FOR(j, 1, M) {
			add[i][j] = add[i][j - 1] + add[i][j];
		}
	}
	FOR(j, 0, M) {
		FOR(i, 1, N) {
			add[i][j] = add[i - 1][j] + add[i][j];
		}
	}
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			board[i][j] += add[i][j];
			if (board[i][j] > 0) {
				answer++;
			}
		}
	}
	return answer;
}