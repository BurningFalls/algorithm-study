#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define tiii tuple<int, int, int>

bool visited[2001][2001];

int BFS(int x) {
	priority_queue<tiii> pq;
	memset(visited, 0, sizeof(visited));
	pq.push({ 0, 1, 0 });
	visited[1][0] = 1;
	while (!pq.empty()) {
		int cnt = -get<0>(pq.top());
		int n = get<1>(pq.top());
		int st = get<2>(pq.top());
		pq.pop();
		if (n == x)
			return cnt;
		if (n * 2 <= 2000 && !visited[n * 2][st]) {
			visited[n * 2][n] = 1;
			pq.push({ -(cnt + 2), n * 2, n });
		}
		if (st != 0 && n + st <= 2000 && !visited[n + st][st]) {
			visited[n + st][st] = 1;
			pq.push({ -(cnt + 1), n + st, st });
		}
		if (n > 0 && !visited[n - 1][st]) {
			visited[n - 1][st] = 1;
			pq.push({ -(cnt + 1), n - 1, st });
		}
	}
}

int main() {
	FASTIO;
	int S;
	cin >> S;
	cout << BFS(S);

	return 0;
}