#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

struct NODE {
	int Ry;
	int Rx;
	int By;
	int Bx;

	bool operator==(NODE a) {
		return Ry == a.Ry && Rx == a.Rx && By == a.By && Bx == a.Bx;
	}
};

int visited[10][10][10][10] = { 0, };
queue<NODE> q;

NODE Move(NODE node, int idx, int N, int M, vector<vector<char>> Map) {
	pii R = { node.Ry, node.Rx };
	pii B = { node.By, node.Bx };
	bool Rflag = false;
	bool Bflag = false;
	if (idx == 0) {
		if (R.first == B.first) {
			if (R.second < B.second) {
				int next = R.second;
				ROF(i, R.second - 1, 0) {
					if (Map[R.first][i] == '#') break;
					if (Map[R.first][i] == 'O') {
						Rflag = true;
					}
					next = i;
				}
				if (!Rflag) {
					R.second = next;
					Map[R.first][R.second] = 'R';
				}
				next = B.second;
				ROF(i, B.second - 1, 0) {
					if (Map[B.first][i] == '#' || Map[B.first][i] == 'R') break;
					if (Map[B.first][i] == 'O') {
						Bflag = true;
					}
					next = i;
				}
				if (!Bflag) {
					B.second = next;
				}
			}
			else if (B.second < R.second) {
				int next = B.second;
				ROF(i, B.second - 1, 0) {
					if (Map[B.first][i] == '#') break;
					if (Map[B.first][i] == 'O') {
						Bflag = true;
					}
					next = i;
				}
				if (!Bflag) {
					B.second = next;
					Map[B.first][B.second] = 'B';
				}
				next = R.second;
				ROF(i, R.second - 1, 0) {
					if (Map[R.first][i] == '#' || Map[R.first][i] == 'B') break;
					if (Map[R.first][i] == 'O') {
						Rflag = true;
					}
					next = i;
				}
				if (!Rflag) {
					R.second = next;
				}
			}
		}
		else if (R.first != B.first) {
			int next = R.second;
			ROF(i, R.second - 1, 0) {
				if (Map[R.first][i] == '#') break;
				if (Map[R.first][i] == 'O') {
					Rflag = true;
				}
				next = i;
			}
			if (!Rflag) {
				R.second = next;
			}
			next = B.second;
			ROF(i, B.second - 1, 0) {
				if (Map[B.first][i] == '#') break;
				if (Map[B.first][i] == 'O') {
					Bflag = true;
				}
				next = i;
			}
			if (!Bflag) {
				B.second = next;
			}
		}
	}
	else if (idx == 1) {
		if (R.first == B.first) {
			if (R.second > B.second) {
				int next = R.second;
				FOR(i, R.second + 1, M - 1) {
					if (Map[R.first][i] == '#') break;
					if (Map[R.first][i] == 'O') {
						Rflag = true;
					}
					next = i;
				}
				if (!Rflag) {
					R.second = next;
					Map[R.first][R.second] = 'R';
				}
				next = B.second;
				FOR(i, B.second + 1, M - 1) {
					if (Map[B.first][i] == '#' || Map[B.first][i] == 'R') break;
					if (Map[B.first][i] == 'O') {
						Bflag = true;
					}
					next = i;
				}
				if (!Bflag) {
					B.second = next;
				}
			}
			else if (B.second > R.second) {
				int next = B.second;
				FOR(i, B.second + 1, M - 1) {
					if (Map[B.first][i] == '#') break;
					if (Map[B.first][i] == 'O') {
						Bflag = true;
					}
					next = i;
				}
				if (!Bflag) {
					B.second = next;
					Map[B.first][B.second] = 'B';
				}
				next = R.second;
				FOR(i, R.second + 1, M - 1) {
					if (Map[R.first][i] == '#' || Map[R.first][i] == 'B') break;
					if (Map[R.first][i] == 'O') {
						Rflag = true;
					}
					next = i;
				}
				if (!Rflag) {
					R.second = next;
				}
			}
		}
		else if (R.first != B.first) {
			int next = R.second;
			FOR(i, R.second + 1, M - 1) {
				if (Map[R.first][i] == '#') break;
				if (Map[R.first][i] == 'O') {
					Rflag = true;
				}
				next = i;
			}
			if (!Rflag) {
				R.second = next;
			}
			next = B.second;
			FOR(i, B.second + 1, M - 1) {
				if (Map[B.first][i] == '#') break;
				if (Map[B.first][i] == 'O') {
					Bflag = true;
				}
				next = i;
			}
			if (!Bflag) {
				B.second = next;
			}
		}
	}
	else if (idx == 2) {
		if (R.second == B.second) {
			if (R.first < B.first) {
				int next = R.first;
				ROF(i, R.first - 1, 0) {
					if (Map[i][R.second] == '#') break;
					if (Map[i][R.second] == 'O') {
						Rflag = true;
					}
					next = i;
				}
				if (!Rflag) {
					R.first = next;
					Map[R.first][R.second] = 'R';
				}
				next = B.first;
				ROF(i, B.first - 1, 0) {
					if (Map[i][B.second] == '#' || Map[i][B.second] == 'R') break;
					if (Map[i][B.second] == 'O') {
						Bflag = true;
					}
					next = i;
				}
				if (!Bflag) {
					B.first = next;
				}
			}
			else if (B.first < R.first) {
				int next = B.first;
				ROF(i, B.first - 1, 0) {
					if (Map[i][B.second] == '#') break;
					if (Map[i][B.second] == 'O') {
						Bflag = true;
					}
					next = i;
				}
				if (!Bflag) {
					B.first = next;
					Map[B.first][B.second] = 'B';
				}
				next = R.first;
				ROF(i, R.first - 1, 0) {
					if (Map[i][R.second] == '#' || Map[i][R.second] == 'B') break;
					if (Map[i][R.second] == 'O') {
						Rflag = true;
					}
					next = i;
				}
				if (!Rflag) {
					R.first = next;
				}
			}
		}
		else if (R.second != B.second) {
			int next = R.first;
			ROF(i, R.first - 1, 0) {
				if (Map[i][R.second] == '#') break;
				if (Map[i][R.second] == 'O') {
					Rflag = true;
				}
				next = i;
			}
			if (!Rflag) {
				R.first = next;
			}
			next = B.first;
			ROF(i, B.first - 1, 0) {
				if (Map[i][B.second] == '#') break;
				if (Map[i][B.second] == 'O') {
					Bflag = true;
				}
				next = i;
			}
			if (!Bflag) {
				B.first = next;
			}
		}
	}
	else if (idx == 3) {
		if (R.second == B.second) {
			if (R.first > B.first) {
				int next = R.first;
				FOR(i, R.first + 1, N - 1) {
					if (Map[i][R.second] == '#') break;
					if (Map[i][R.second] == 'O') {
						Rflag = true;
					}
					next = i;
				}
				if (!Rflag) {
					R.first = next;
					Map[R.first][R.second] = 'R';
				}
				next = B.first;
				FOR(i, B.first + 1, N - 1) {
					if (Map[i][B.second] == '#' || Map[i][B.second] == 'R') break;
					if (Map[i][B.second] == 'O') {
						Bflag = true;
					}
					next = i;
				}
				if (!Bflag) {
					B.first = next;
				}
			}
			else if (B.first > R.first) {
				int next = B.first;
				FOR(i, B.first + 1, N - 1) {
					if (Map[i][B.second] == '#') break;
					if (Map[i][B.second] == 'O') {
						Bflag = true;
					}
					next = i;
				}
				if (!Bflag) {
					B.first = next;
					Map[B.first][B.second] = 'B';
				}
				next = R.first;
				FOR(i, R.first + 1, N - 1) {
					if (Map[i][R.second] == '#' || Map[i][R.second] == 'B') break;
					if (Map[i][R.second] == 'O') {
						Rflag = true;
					}
					next = i;
				}
				if (!Rflag) {
					R.first = next;
				}
			}
		}
		else if (R.second != B.second) {
			int next = R.first;
			FOR(i, R.first + 1, N - 1) {
				if (Map[i][R.second] == '#') break;
				if (Map[i][R.second] == 'O') {
					Rflag = true;
				}
				next = i;
			}
			if (!Rflag) {
				R.first = next;
			}
			next = B.first;
			FOR(i, B.first + 1, N - 1) {
				if (Map[i][B.second] == '#') break;
				if (Map[i][B.second] == 'O') {
					Bflag = true;
				}
				next = i;
			}
			if (!Bflag) {
				B.first = next;
			}
		}
	}
	if (Bflag) {
		return { -1, -1, -1, -1 };
	}
	else if (Rflag) {
		return { -1, -1, -1, 1 };
	}
	else {
		return { R.first, R.second, B.first, B.second };
	}
}

int BFS(NODE sn, int N, int M, vector<vector<char>>& Map) {
	q.push({ sn.Ry, sn.Rx, sn.By, sn.Bx });
	visited[sn.Ry][sn.Rx][sn.By][sn.Bx] = 1;
	while (!q.empty()) {
		NODE cur = q.front();
		q.pop();
		FOR(i, 0, 3) {
			NODE next = Move(cur, i, N, M, Map);
			NODE a = { -1, -1, -1, -1 };
			NODE b = { -1, -1, -1, 1 };
			if (next == b) {
				return visited[cur.Ry][cur.Rx][cur.By][cur.Bx];
			}
			if (next == a) {
				continue;
			}
			if (visited[next.Ry][next.Rx][next.By][next.Bx]) continue;
			visited[next.Ry][next.Rx][next.By][next.Bx] = visited[cur.Ry][cur.Rx][cur.By][cur.Bx] + 1;
			q.push(next);
		}
	}
	return -1;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<vector<char>> Map(N, vector<char>(M));
	int ry = 0, rx = 0, by = 0, bx = 0;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
			if (Map[i][j] == 'R') {
				ry = i;
				rx = j;
				Map[i][j] = '.';
			}
			else if (Map[i][j] == 'B') {
				by = i;
				bx = j;
				Map[i][j] = '.';
			}
		}
	}
	NODE sn = { ry, rx, by, bx };
	cout << BFS(sn, N, M, Map);


	return 0;
}