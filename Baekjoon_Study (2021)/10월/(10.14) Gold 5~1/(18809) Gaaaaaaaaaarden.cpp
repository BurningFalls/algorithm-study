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

int Do(int N, int M, int G, int R, vector<vector<int>>& Map, vector<pii>& possi_v, vector<int>& possi_idx) {
	vector<vector<int>> Gvisited(N, vector<int>(M, 0));
	vector<vector<int>> Rvisited(N, vector<int>(M, 0));
	vector<vector<int>> Nouse(N, vector<int>(M, 0));
	int plen = LEN(possi_v);
	vector<int> dy = { -1, 1, 0, 0 };
	vector<int> dx = { 0, 0, -1, 1 };
	queue<pii> Gq, Rq;
	FOR(i, 0, plen - 1) {
		if (possi_idx[i] == 1) {
			Gq.push(possi_v[i]);
			Gvisited[possi_v[i].first][possi_v[i].second] = 1;
		}
		else if (possi_idx[i] == 2) {
			Rq.push(possi_v[i]);
			Rvisited[possi_v[i].first][possi_v[i].second] = 1;
		}
	}
	int flower_cnt = 0;
	while (!Gq.empty() || !Rq.empty()) {
		int Glen = LEN(Gq);
		int Rlen = LEN(Rq);
		while (Glen--) {
			int y = Gq.front().first;
			int x = Gq.front().second;
			Gq.pop();
			if (Nouse[y][x]) continue;
			FOR(i, 0, 3) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				if (Map[ny][nx] == 0) continue;
				if (Gvisited[ny][nx]) continue;
				Gvisited[ny][nx] = Gvisited[y][x] + 1;
				Gq.push({ ny, nx });
			}
		}
		while (Rlen--) {
			int y = Rq.front().first;
			int x = Rq.front().second;
			Rq.pop();
			FOR(i, 0, 3) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				if (Map[ny][nx] == 0) continue;
				if (Rvisited[ny][nx]) continue;
				Rvisited[ny][nx] = Rvisited[y][x] + 1;
				if (Gvisited[ny][nx] == Rvisited[ny][nx]) {
					Nouse[ny][nx] = 1;
					flower_cnt++;
				}
				else {
					Rq.push({ ny, nx });
				}
			}
		}
	}
	return flower_cnt;
}

int main() {
	FASTIO;
	int N, M, G, R;
	cin >> N >> M >> G >> R;
	vector<vector<int>> Map(N, vector<int>(M));
	vector<pii> possi_v;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
			if (Map[i][j] == 2) {
				possi_v.push_back({ i, j });
			}
		}
	}
	int plen = LEN(possi_v);
	vector<int> possi_idx(plen, 0);
	FOR(i, plen - R - G, plen - R - 1) {
		possi_idx[i] = 1;
	}
	FOR(i, plen - R, plen - 1) {
		possi_idx[i] = 2;
	}
	bool flag = true;
	int ans = 0;
	while (flag) {
		ans = max(ans, Do(N, M, G, R, Map, possi_v, possi_idx));
		flag = next_permutation(ALL(possi_idx));
	}
	cout << ans;


	return 0;
}