#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())
#define INF 987654321

int N, P;
vector<int> edge[801];
int C[801][801];
int F[801][801];
int Prev[801];

void Edge_Connection() {
	FOR(i, 1, N) {
		edge[2 * i - 1].push_back(2 * i);
		edge[2 * i].push_back(2 * i - 1);
		C[2 * i - 1][2 * i] = 1;
		C[2 * i][2 * i - 1] = 0;
	}

	FOR(p, 1, P) {
		int a, b;
		cin >> a >> b;
		edge[2 * a].push_back(2 * b - 1);
		edge[2 * b - 1].push_back(2 * a);
		C[2 * a][2 * b - 1] = 1;
		C[2 * b - 1][2 * a] = 0;
		edge[2 * b].push_back(2 * a - 1);
		edge[2 * a - 1].push_back(2 * b);
		C[2 * b][2 * a - 1] = 1;
		C[2 * a - 1][2 * b] = 0;
	}
}

int main() {
	FASTIO;
	cin >> N >> P;
	Edge_Connection();

	int ans = 0;
	while (true) {
		MEMSET(Prev, -1);
		queue<int> q;
		q.push(2);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int next : edge[cur]) {
				if (Prev[next] != -1) continue;
				if (C[cur][next] - F[cur][next] <= 0) continue;
				q.push(next);
				Prev[next] = cur;
				if (next == 3)
					break;
			}
		}
		if (Prev[3] == -1)
			break;
		int mini = INF;
		for (int node = 3; node != 2; node = Prev[node])
			mini = min(mini, C[Prev[node]][node] - F[Prev[node]][node]);
		for (int node = 3; node != 2; node = Prev[node]) {
			F[Prev[node]][node] += mini;
			F[node][Prev[node]] -= mini;
		}
		ans += mini;
	}
	cout << ans;

	return 0;
}