#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int, int>

int Size;
int Game_Board[52][52];
int Table[52][52] = { 0, };
int Piece[52][52];
bool visited_Table[52][52] = { 0, };
int ans_cnt = 0;

void Rotate_GameBoard() {
	int tmp_GameBoard[52][52];
	FOR(i, 0, Size + 1) {
		FOR(j, 0, Size + 1) {
			tmp_GameBoard[i][j] = Game_Board[j][(Size + 1) - i];
		}
	}
	FOR(i, 0, Size + 1) {
		FOR(j, 0, Size + 1) {
			Game_Board[i][j] = tmp_GameBoard[i][j];
		}
	}
}

int is_Fit(int sy, int sx, int miny, int maxy, int minx, int maxx) {
	int height = maxy - miny + 1;
	int width = maxx - minx + 1;
	int block_cnt = 0;
	FOR(i, sy, sy + height - 1) {
		FOR(j, sx, sx + width - 1) {
			int piecey = miny + (i - sy);
			int piecex = minx + (j - sx);
			if (Piece[piecey][piecex] == -1) continue;
			if (Piece[piecey][piecex] == 1 && Game_Board[i][j] == 0) {
				block_cnt++;
				continue;
			}
			if (Piece[piecey][piecex] == 0 && Game_Board[i][j] == 1) continue;
			return -1;
		}
	}
	FOR(i, sy, sy + height - 1) {
		FOR(j, sx, sx + width - 1) {
			int piecey = miny + (i - sy);
			int piecex = minx + (j - sx);
			if (Piece[piecey][piecex] == 1 && Game_Board[i][j] == 0) {
				Game_Board[i][j] = 1;
			}
		}
	}
	return block_cnt;
}

void Explore_GameBoard(int miny, int maxy, int minx, int maxx) {
	int height = maxy - miny + 1;
	int width = maxx - minx + 1;
	FOR(k, 1, 4) {
		FOR(sy, 0, (Size + 1) - height + 1) {
			FOR(sx, 0, (Size + 1) - width + 1) {
				int Fitting = is_Fit(sy, sx, miny, maxy, minx, maxx);
				if (Fitting != -1) {
					ans_cnt += Fitting;
					return;
				}
			}
		}
		Rotate_GameBoard();
	}
}

void Find_Piece(int sy, int sx) {
	memset(Piece, -1, sizeof(Piece));
	queue<pii> q;
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	int minx, maxx, miny, maxy;
	q.push({ sy, sx });
	visited_Table[sy][sx] = 1;
	Piece[sy][sx] = 1;
	minx = sx, maxx = sx, miny = sy, maxy = sy;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny > Size + 1 || nx > Size + 1) continue;
			minx = min(minx, nx); maxx = max(maxx, nx);
			miny = min(miny, ny); maxy = max(maxy, ny);
			if (Table[ny][nx] == 0) {
				Piece[ny][nx] = 0;
				continue;
			}
			if (visited_Table[ny][nx]) continue;
			visited_Table[ny][nx] = 1;
			Piece[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
	Explore_GameBoard(miny, maxy, minx, maxx);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
	int answer = -1;
	Size = game_board.size();
	FOR(i, 0, Size + 1) {
		Game_Board[0][i] = 1;
		Game_Board[Size + 1][i] = 1;
		Game_Board[i][0] = 1;
		Game_Board[i][Size + 1] = 1;
	}
	FOR(i, 0, Size - 1) {
		FOR(j, 0, Size - 1) {
			Game_Board[i + 1][j + 1] = game_board[i][j];
			Table[i + 1][j + 1] = table[i][j];
		}
	}
	FOR(i, 1, Size) {
		FOR(j, 1, Size) {
			if (Table[i][j] == 0) continue;
			if (visited_Table[i][j]) continue;
			Find_Piece(i, j);
		}
	}
	answer = ans_cnt;
	return answer;
}