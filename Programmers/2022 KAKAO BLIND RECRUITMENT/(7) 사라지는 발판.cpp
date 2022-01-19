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

int N, M;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

pii Amove(vector<vector<int>>&board, pii aloc, pii bloc);
pii Bmove(vector<vector<int>>&board, pii aloc, pii bloc);

pii Amove(vector<vector<int>>& board, pii aloc, pii bloc) {
	if (board[aloc.first][aloc.second] == 0) {
		return { 0, false };
	}
	int max_move = -1;
	int min_move = INF;
	bool flag = true;
	bool move_flag = false;
	FOR(i, 0, 3) {
		int ny = aloc.first + dy[i];
		int nx = aloc.second + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (board[ny][nx] == 0) continue;
		move_flag = true;
		board[aloc.first][aloc.second] = 0;
		pii tmp = Bmove(board, { ny, nx }, bloc);
		if (tmp.second == true) {
			max_move = max(max_move, tmp.first);
		}
		else if (tmp.second == false) {
			min_move = min(min_move, tmp.first);
		}
		flag &= tmp.second;
		board[aloc.first][aloc.second] = 1;
	}
	if (!move_flag) {
		return { 0, false };
	}
	if (flag) {
		return { max_move + 1, false };
	}
	else if (!flag) {
		return { min_move + 1, true };
	}
}

pii Bmove(vector<vector<int>>& board, pii aloc, pii bloc) {
	if (board[bloc.first][bloc.second] == 0) {
		return { 0, false };
	}
	int max_move = -1;
	int min_move = INF;
	bool flag = true;
	bool move_flag = false;
	FOR(i, 0, 3) {
		int ny = bloc.first + dy[i];
		int nx = bloc.second + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (board[ny][nx] == 0) continue;
		move_flag = true;
		board[bloc.first][bloc.second] = 0;
		pii tmp = Amove(board, aloc, { ny, nx });
		if (tmp.second == true) {
			max_move = max(max_move, tmp.first);
		}
		else if (tmp.second == false) {
			min_move = min(min_move, tmp.first);
		}
		flag &= tmp.second;
		board[bloc.first][bloc.second] = 1;
	}
	if (!move_flag) {
		return { 0, false };
	}
	if (flag) {
		return { max_move + 1, false };
	}
	else if (!flag) {
		return { min_move + 1, true };
	}
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
	int answer = -1;
	N = LEN(board);
	M = LEN(board[0]);
	pii tmp = Amove(board, { aloc[0], aloc[1] }, { bloc[0], bloc[1] });
	answer = tmp.first;

	return answer;
}