#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 2100000000

int N;
int arr[1001][1001];
int dist[1000001];

pii Find(int node) {
	node -= 1;
	int y = node / N + 1;
	int x = node % N + 1;
	return { y, x };
}

void DT() {
	priority_queue<pii> pq;
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	pq.push({ 0, 1 });
	dist[1] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		pii cur_pos = Find(cur);
		int y = (cur - 1) / N + 1;
		int x = (cur - 1) % N + 1;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
			int next = N * (ny - 1) + nx;
			int ncost = abs(arr[y][x] - arr[ny][nx]);
			ncost = max(ncost, cost);
			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ -ncost, next });
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N * N)
		dist[i] = INF;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> arr[i][j];
		}
	}
	DT();
	cout << dist[N * N];


	return 0;
}