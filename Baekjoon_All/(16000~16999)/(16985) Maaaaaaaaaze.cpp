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

int arr[5][5][5];
int cube[5][5][5];
vector<int> dz = { 1, -1, 0, 0, 0, 0 };
vector<int> dy = { 0, 0, 1, -1, 0, 0 };
vector<int> dx = { 0, 0, 0, 0, 1, -1 };

struct NODE {
	int z;
	int y;
	int x;
};

void Rotate(int floor) {
	int arr[5][5];
	FOR(i, 0, 4) {
		FOR(j, 0, 4) {
			arr[i][j] = cube[floor][4 - j][i];
		}
	}
	FOR(i, 0, 4) {
		FOR(j, 0, 4) {
			cube[floor][i][j] = arr[i][j];
		}
	}
}

int BFS() {
	queue<NODE> q;
	int visited[5][5][5] = { 0, };
	if (cube[0][0][0] == 0)
		return INF;
	q.push({ 0, 0, 0 });
	visited[0][0][0] = 1;
	while (!q.empty()) {
		int z = q.front().z;
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		if (z == 4 && y == 4 && x == 4) {
			return visited[4][4][4] - 1;
		}
		FOR(i, 0, 5) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nz < 0 || ny < 0 || nx < 0 || nz > 4 || ny > 4 || nx > 4) continue;
			if (cube[nz][ny][nx] == 0) continue;
			if (visited[nz][ny][nx]) continue;
			visited[nz][ny][nx] = visited[z][y][x] + 1;
			q.push({ nz, ny, nx });
		}
	}
	return INF;
}

int Do(vector<int>& per) {
	FOR(k, 0, 4) {
		FOR(i, 0, 4) {
			FOR(j, 0, 4) {
				cube[k][i][j] = arr[per[k]][i][j];
			}
		}
	}

	int mini = INF;
	FOR(a, 0, 4) {
		Rotate(0);
		FOR(b, 0, 4) {
			Rotate(1);
			FOR(c, 0, 4) {
				Rotate(2);
				FOR(d, 0, 4) {
					Rotate(3);
					FOR(e, 0, 4) {
						Rotate(4);
						mini = min(mini, BFS());
					}
				}
			}
		}
	}
	return mini;
}

int main() {
	FASTIO;
	FOR(k, 0, 4) {
		FOR(i, 0, 4) {
			FOR(j, 0, 4) {
				cin >> arr[k][i][j];
			}
		}
	}
	vector<int> per = { 0, 1, 2, 3, 4 };
	bool flag = true;
	int ans = INF;
	while (flag) {
		ans = min(ans, Do(per));
		flag = next_permutation(ALL(per));
	}
	cout << (ans != INF ? ans : -1);

	return 0;
}