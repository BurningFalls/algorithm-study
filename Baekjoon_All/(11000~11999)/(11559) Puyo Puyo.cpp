#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char arr[14][8];
int visited[14][8] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool check[101];

int BFS(int a, int b, int idx) {
	int cnt = 1;
	queue<pii> q;
	q.push({ a, b });
	visited[a][b] = idx;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > 12 || nx > 6) continue;
			if (visited[ny][nx]) continue;
			if (arr[ny][nx] == arr[a][b]) {
				visited[ny][nx] = idx;
				q.push({ ny, nx });
				cnt++;
			}
		}
	}
	return cnt;
}

void Erase() {
	FOR(i, 1, 12) {
		FOR(j, 1, 6) {
			if (check[visited[i][j]])
				arr[i][j] = '.';
		}
	}
	vector<char> v[7];
	FOR(i, 1, 6) {
		FOR(j, 0, 11) {
			if (arr[12 - j][i] == '.') continue;
			v[i].push_back(arr[12 - j][i]);
		}
	}
	FOR(i, 1, 6) {
		int len = v[i].size();
		FOR(j, 0, len - 1) {
			arr[12 - j][i] = v[i][j];
		}
		FOR(j, len, 12) {
			arr[12 - j][i] = '.';
		}
	}
}

bool Find() {
	memset(visited, 0, sizeof(visited));
	memset(check, 0, sizeof(check));
	FOR(i, 1, 12) {
		FOR(j, 1, 6) {
			if (arr[i][j] == '.')
				visited[i][j] = 1;
		}
	}
	bool is_exist = false;
	int flag = 2;
	FOR(i, 1, 12) {
		FOR(j, 1, 6) {
			if (visited[i][j]) continue;
			int temp = BFS(i, j, flag);
			if (temp >= 4) {
				is_exist = true;
				check[flag] = 1;
			}
			flag++;
		}
	}
	if (is_exist)
		Erase();
	return is_exist;
}

int main() {
	FASTIO;
	int ans = 0;
	FOR(i, 1, 12) {
		FOR(j, 1, 6) {
			cin >> arr[i][j];
		}
	}
	while (Find()) {
		ans++;
	}
	cout << ans;

	return 0;
}