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
#define INF 2e9
#define LINF 1e18

int N;
int Map[1001][1001];
vector<pii> soldier;
pii home;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
ll Dist[1001][1001];
ll Dist2[7][7];
int soldier_cnt = 0;

void DT(int sy, int sx, int idx) {
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			Dist[i][j] = LINF;
		}
	}
	PQ<pair<ll, pii>> pq;
	Dist[sy][sx] = 0;
	pq.push({ 0, {sy, sx} });
	while (!pq.empty()) {
		ll cost = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if (Dist[y][x] < cost) continue;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
			ll next_cost = cost;
			if (Map[ny][nx] >= 1) {
				next_cost += Map[ny][nx];
			}
			if (Dist[ny][nx] > next_cost) {
				Dist[ny][nx] = next_cost;
				pq.push({ -next_cost, {ny, nx} });
			}
		}
	}
	FOR(i, 0, LEN(soldier)) {
		if (i == idx) {
			Dist2[idx][idx] = 0;
		}
		else if (i == 0) {
			int y = home.first;
			int x = home.first;
			Dist2[idx][0] = Dist[y][x];
		}
		else {
			int y = soldier[i - 1].first;
			int x = soldier[i - 1].second;
			Dist2[idx][i] = Dist[y][x];
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, 6) {
		FOR(j, 0, 6) {
			Dist2[i][j] = LINF;
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
			if (Map[i][j] == 0) {
				soldier.push_back({ i, j });
			}
			else if (Map[i][j] == -1) {
				home = { i, j };
			}
		}
	}
	FOR(i, 0, LEN(soldier)) {
		if (i == 0) {
			DT(home.first, home.second, i);
		}
		else {
			DT(soldier[i - 1].first, soldier[i - 1].second, i);
		}
	}
	vector<int> tmp;
	FOR(i, 1, LEN(soldier)) {
		tmp.push_back(i);
	}
	bool flag = true;
	ll mini = LINF;
	while (flag) {
		ll sum = 0;
		int prev = 0;
		FOR(i, 0, LEN(tmp) - 1) {
			int cur = tmp[i];
			sum += Dist2[prev][cur];
			prev = cur;
		}
		sum += Dist2[prev][0];
		mini = min(mini, sum);
		flag = next_permutation(ALL(tmp));
	}
	cout << mini;


	return 0;
}