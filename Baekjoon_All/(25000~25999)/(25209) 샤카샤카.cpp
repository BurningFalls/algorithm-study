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
#define INF int(2e9)
#define LINF ll(1e18)

int N, M;
vector<vector<char>> input_Map(32, vector<char>(32));
vector<vector<int>> Map(12, vector<int>(12, -1));
vector<vector<int>> visited(12, vector<int>(12, 0));
vector<vector<int>> Number(12, vector<int>(12, -1));

void Make_Index() {
	vector<vector<vector<char>>> block(7, vector<vector<char>>(4, vector<char>(4)));
	block[0] = { {'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'} };
	block[1] = { {'#', '#', '#'}, {'#', '#', '#'}, {'#', '#', '#'} };
	block[2] = { {'#', '.', '.'}, {'#', '#', '.'}, {'#', '#', '#'} };
	block[3] = { {'#', '#', '#'}, {'.', '#', '#'}, {'.', '.', '#'} };
	block[4] = { {'#', '#', '#'}, {'#', '#', '.'}, {'#', '.', '.'} };
	block[5] = { {'.', '.', '#'}, {'.', '#', '#'}, {'#', '#', '#'} };
	for (int i = 1; i <= 3 * N; i += 3) {
		for (int j = 1; j <= 3 * M; j += 3) {
			for (int k = 0; k <= 5; k++) {
				bool flag = true;
				for (int y = 0; y <= 2; y++) {
					for (int x = 0; x <= 2; x++) {
						if (y == 1 && x == 1) continue;
						if (input_Map[i + y][j + x] != block[k][y][x]) {
							flag = false;
						}
					}
				}
				if (flag) {
					Map[i / 3 + 1][j / 3 + 1] = k;
					if (k == 1) {
						if (input_Map[i + 1][j + 1] == '#') continue;
						Number[i / 3 + 1][j / 3 + 1] = input_Map[i + 1][j + 1] - '0';
					}
				}
			}
		}
	}
}

bool Find_Boundary1(int y, int x) {
	int dy[4] = { 1, 1, -1, -1 };
	int dx[4] = { -1, 1, 1, -1 };
	int dy2[4] = { 1, 0, -1, 0 };
	int dx2[4] = { 0, 1, 0, -1 };
	int num[4] = { 4, 2, 5, 3 };
	FOR(i, 0, 3) {
		while (Map[y + dy[i]][x + dx[i]] == num[i]) {
			y += dy[i];
			x += dx[i];
			visited[y][x] = 1;
		}
		if (Map[y + dy2[i]][x + dx2[i]] != num[(i + 1) % 4]) {
			return false;
		}
		y += dy2[i];
		x += dx2[i];
		visited[y][x] = 1;
	}
	return true;
}

bool Find_Boundary2(int sy, int sx) {
	int dy[4] = { 1, 0, -1, 0 };
	int dx[4] = { 0, 1, 0, -1 };
	int y = sy, x = sx;
	FOR(i, 0, 3) {
		while (Map[y + dy[i]][x + dx[i]] == 0) {
			y += dy[i];
			x += dx[i];
			visited[y][x] = 1;
		}
	}
	if (y != sy || x != sx) {
		return false;
	}
	return true;
}

bool is_Empty1(int sy, int sx) {
	int y = sy, x = sx;
	while (Map[y][x] == 4) {
		int ny = y + 1, nx = x;
		while (visited[ny][nx] != 1) {
			if (Map[ny][nx] != 0) {
				return false;
			}
			visited[ny][nx] = 1;
			ny += 1;
		}
		y += 1;
		x -= 1;
	}

	y = sy, x = sx + 1;
	while (Map[y][x] == 3) {
		int ny = y + 1, nx = x;
		while (visited[ny][nx] != 1) {
			if (Map[ny][nx] != 0) {
				return false;
			}
			visited[ny][nx] = 1;
			ny += 1;
		}
		y += 1;
		x += 1;
	}
	return true;
}

bool is_Empty2(int y, int x) {
	if (Map[y + 1][x] != 0 || Map[y][x + 1] != 0) {
		return true;
	}
	x += 1;
	while (Map[y][x] == 0) {
		int ny = y + 1, nx = x;
		while (visited[ny][nx] != 1) {
			if (Map[ny][nx] != 0) {
				return false;
			}
			visited[ny][nx] = 1;
			ny += 1;
		}
		x += 1;
	}
	return true;
}

bool Check_Rec1() {
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (Map[i][j] == 4 && !visited[i][j]) {
				bool flag1 = Find_Boundary1(i, j);
				if (!flag1) {
					return false;
				}
				bool flag2 = is_Empty1(i, j);
				if (!flag2) {
					return false;
				}
			}
		}
	}
	return true;
}

bool Check_Rec2() {
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (visited[i][j]) continue;
			if (Map[i][j] != 1 && Map[i][j] != 0) {
				return false;
			}
			if (Map[i][j] == 0) {
				bool flag1 = Find_Boundary2(i, j);
				if (!flag1) {
					return false;
				}
				bool flag2 = is_Empty2(i, j);
				if (!flag2) {
					return false;
				}
			}
		}
	}
	return true;
}

int Count_Triangle(int y, int x) {
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	int cnt = 0;
	FOR(i, 0, 3) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (2 <= Map[ny][nx] && Map[ny][nx] <= 5) {
			cnt++;
		}
	}
	return cnt;
}

bool Check_Number() {
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (Number[i][j] == -1) continue;
			if (Number[i][j] != Count_Triangle(i, j)) {
				return false;
			}
		}
	}
	return true;
}

void Input() {
	cin >> N >> M;
	FOR(i, 1, 3 * N) {
		FOR(j, 1, 3 * M) {
			cin >> input_Map[i][j];
		}
	}
}

int main() {
	FASTIO;
	Input();
	Make_Index();
	if (!Check_Rec1()) {
		cout << "NO";
		return 0;
	}
	if (!Check_Rec2()) {
		cout << "NO";
		return 0;
	}
	if (!Check_Number()) {
		cout << "NO";
		return 0;
	}
	cout << "YES";

	return 0;
}