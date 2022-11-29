#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int H, W;
	cin >> H >> W;
	vector<vector<int>> Map(H, vector<int>(W));
	vector<vector<int>> visited(H, vector<int>(W, 0));
	FOR(i, 0, H - 1) {
		FOR(j, 0, W - 1) {
			cin >> Map[i][j];
			if (Map[i][j] == -1) {
				visited[i][j] = -1;
			}
		}
	}

	int cnt = 0;
	vector<int> dy = { -1, 1, 0, 0 };
	vector<int> dx = { 0, 0, -1, 1 };
	PQ<pair<int, pii>> pq;
	FOR(i, 0, H - 1) {
		FOR(j, 0, W - 1) {
			if (Map[i][j] <= 0) continue;
			bool flag = false;
			FOR(k, 0, 3) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
				if (Map[ny][nx] == -1) continue;
				if (Map[ny][nx] == Map[i][j] + 1) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				pq.push({ Map[i][j], {i, j} });
				cnt++;
			}
		}
	}

	while (!pq.empty()) {
		int num = pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if (visited[y][x] != 0) continue;
		visited[y][x] = num;
		if (num == 1) continue;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
			if (visited[ny][nx] != 0) continue;
			pq.push({ visited[y][x] - 1, {ny, nx} });
		}
	}

	bool flag = true;
	FOR(i, 0, H - 1) {
		FOR(j, 0, W - 1) {
			if (Map[i][j] != visited[i][j]) {
				flag = false;
			}
		}
	}
	cout << (flag ? cnt : -1);

	return 0;
}