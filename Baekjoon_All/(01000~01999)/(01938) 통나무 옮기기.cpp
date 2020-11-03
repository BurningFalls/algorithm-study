#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
char Map[52][52];
int dy[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
int dx[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
vector<pii> logs_v, ends_v;
pii log_mid, end_mid;
bool log_vert = false;
bool end_vert = false;
// 0: horizontal, 1: vertical
int visited[51][51][2] = { 0, };
queue<pair<pii, bool>> q;
int arr[3];

void func(int my, int mx, bool vert) {
	bool flag = true;
	if (my == 2 && mx == 3 && vert == true) {
		int a = 1;
	}
	for (int i = 0; i <= 2; i++) {
		int nmy = my + dy[arr[i]];
		int nmx = mx + dx[arr[i]];
		if (nmy < 1 || nmx < 1 || nmy > N || nmx > N) {
			flag = false; 
			break;
		}
		if (Map[nmy][nmx] == '1') {
			flag = false; 
			break;
		}
	}
	if (flag) {
		int nmy = my + dy[arr[1]];
		int nmx = mx + dx[arr[1]];
		if (!visited[nmy][nmx][vert]) {
			visited[nmy][nmx][vert] = visited[my][mx][vert] + 1;
			q.push({ {nmy, nmx}, vert });
		}
	}
}

void func2(int my, int mx, bool vert, int idx) {
	bool flag = true;
	int tmpy = my + dy[idx] * 2;
	int tmpx = mx + dx[idx] * 2;
	if (tmpy < 1 || tmpx < 1 || tmpy > N || tmpx > N)
		flag = false;
	else if (Map[tmpy][tmpx] == '1')
		flag = false;
	if (flag) {
		int nmy = my + dy[idx];
		int nmx = mx + dx[idx];
		if (!visited[nmy][nmx][vert]) {
			visited[nmy][nmx][vert] = visited[my][mx][vert] + 1;
			q.push({ {nmy, nmx}, vert });
		}
	}
}

void func3(int my, int mx, bool vert) {
	bool flag = true;
	for (int i = 0; i <= 8; i++) {
		if (i == 4) continue;
		int nmy = my + dy[i];
		int nmx = mx + dx[i];
		if (nmy < 1 || nmx < 1 || nmy > N || nmx > N) {
			flag = false; 
			break;
		}
		if (Map[nmy][nmx] == '1') {
			flag = false; 
			break;
		}
	}
	if (flag) {
		bool nvert = !vert;
		if (!visited[my][mx][nvert]) {
			visited[my][mx][nvert] = visited[my][mx][vert] + 1;
			q.push({ {my, mx}, nvert });
		}
	}
}

int BFS() {
	while (!q.empty()) {
		int my = q.front().first.first;
		int mx = q.front().first.second;
		bool vert = q.front().second;
		q.pop();
		if (my == end_mid.first && mx == end_mid.second && vert == end_vert)
			return visited[my][mx][vert] - 1;
		if (vert) {
			arr[0] = 0, arr[1] = 3, arr[2] = 6;
			func(my, mx, vert);
			arr[0] = 2, arr[1] = 5, arr[2] = 8;
			func(my, mx, vert);
			func2(my, mx, vert, 1);
			func2(my, mx, vert, 7);
			func3(my, mx, vert);
		}
		else if (!vert) {
			arr[0] = 0, arr[1] = 1, arr[2] = 2;
			func(my, mx, vert);
			arr[0] = 6, arr[1] = 7, arr[2] = 8;
			func(my, mx, vert);
			func2(my, mx, vert, 3);
			func2(my, mx, vert, 5);
			func3(my, mx, vert);
		}
	}
	return 0;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
			if (Map[i][j] == 'B')
				logs_v.push_back({ i, j });
			if (Map[i][j] == 'E')
				ends_v.push_back({ i, j });
		}
	}
	if (logs_v[0].second == logs_v[1].second && logs_v[1].second == logs_v[2].second)
		log_vert = true;
	log_mid = logs_v[1];
	if (ends_v[0].second == ends_v[1].second && ends_v[1].second == ends_v[2].second)
		end_vert = true;
	end_mid = ends_v[1];
	q.push({ log_mid, log_vert });
	visited[log_mid.first][log_mid.second][log_vert] = 1;
	cout << BFS();

	return 0;
}