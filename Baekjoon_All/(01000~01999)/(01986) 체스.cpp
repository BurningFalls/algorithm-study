#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
bool Map[1001][1001] = { 0, };
bool unsafe[1001][1001] = { 0, };
int dy1[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx1[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy2[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dx2[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
vector<pii> Queen, Knight;

void Set() {
	int cnt;
	cin >> cnt;
	FOR(i, 1, cnt) {
		int y, x;
		cin >> y >> x;
		Map[y][x] = 1;
		Queen.push_back({ y, x });
		unsafe[y][x] = 1;
	}
	cin >> cnt;
	FOR(i, 1, cnt) {
		int y, x;
		cin >> y >> x;
		Map[y][x] = 1;
		Knight.push_back({ y, x });
		unsafe[y][x] = 1;
	}
	cin >> cnt;
	FOR(i, 1, cnt) {
		int y, x;
		cin >> y >> x;
		Map[y][x] = 1;
		unsafe[y][x] = 1;
	}
}

void Move() {
	for (pii n : Queen) {
		int y = n.first;
		int x = n.second;
		FOR(k, 0, 7) {
			int ny = y, nx = x;
			while (true) {
				ny += dy1[k];
				nx += dx1[k];
				if (ny < 1 || nx < 1 || ny > N || nx > M)
					break;
				if (Map[ny][nx])
					break;
				unsafe[ny][nx] = 1;
			}
		}
	}
	for (pii n : Knight) {
		int y = n.first;
		int x = n.second;
		FOR(k, 0, 7) {
			int ny = y + dy2[k];
			int nx = x + dx2[k];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			unsafe[ny][nx] = 1;
		}
	}
}

int Calc() {
	int cnt = 0;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (!unsafe[i][j])
				cnt++;
		}
	}
	return cnt;
}

int main() {
	FASTIO;
	cin >> N >> M;
	Set();
	Move();
	cout << Calc();

	return 0;
}