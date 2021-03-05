#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N, K;
int arr[201][201];
vector<pair<pii, int>> v;
queue<pair<pii, int>> q;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int S, X, Y;
int Time = 0;

bool cmp(pair<pii, int> a, pair<pii, int> b) {
	return a.second < b.second;
}

void BFS() {
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int kind = q.front().second;
		q.pop();
		if (y == 0 && x == 0 && kind == 0) {
			Time++;
			q.push({ {0, 0}, 0 });
			if (Time == S)
				break;
			continue;
		}
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
			if (arr[ny][nx] != 0) continue;
			arr[ny][nx] = kind;
			q.push({ {ny, nx}, kind });
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> K;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> arr[i][j];
			if (arr[i][j] != 0)
				v.push_back({ {i, j}, arr[i][j] });
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (pair<pii, int> x : v) {
		q.push(x);
	}
	q.push({ { 0, 0 }, 0 });
	
	cin >> S >> X >> Y;
	if (S != 0)
		BFS();
	cout << arr[X][Y];

	return 0;
}