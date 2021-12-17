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

struct NODE {
	int x;
	int y;
	int e;
};

vector<NODE> room(1001);
vector<vector<int>> dist(1001, vector<int>(1001));
vector<int> energy(1001, 0);

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 0, N) {
		int x, y, e;
		cin >> x >> y >> e;
		room[i] = { x, y, e };
	}
	FOR(i, 0, N) {
		dist[i][i] = 0;
		FOR(j, i + 1, N) {
			int tmp = abs(room[i].x - room[j].x) + abs(room[i].y - room[j].y);
			dist[i][j] = tmp;
			dist[j][i] = tmp;
		}
	}
	FOR(i, 1, N) {
		energy[i] += max(0, room[0].e - dist[0][i]);
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			energy[j] -= max(0, room[i].e - dist[i][j]);
		}
	}
	int maxi = 0;
	FOR(i, 1, N) {
		maxi = max(maxi, max(0, energy[i]));
	}
	cout << (maxi == 0 ? "IMPOSSIBLE" : to_string(maxi));

	return 0;
}