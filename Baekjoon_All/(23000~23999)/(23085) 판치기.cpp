#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int N, K;
int visited[3001][3001] = { 0, };

int BFS(int sh, int st) {
	queue<pii> q;
	q.push({ sh, st });
	visited[sh][st] = 1;
	while (!q.empty()) {
		int h = q.front().first;
		int t = q.front().second;
		q.pop();
		if (h == 0 && t == N)
			return visited[h][t];
		FOR(i, 0, K) {
			if (h < i || t < K - i) continue;
			int nh = h - i + (K - i);
			int nt = t + i - (K - i);
			if (visited[nh][nt]) continue;
			visited[nh][nt] = visited[h][t] + 1;
			q.push({ nh, nt });
		}
	}
	return 0;
}

int main() {
	FASTIO;
	int Hcnt = 0;
	int Tcnt = 0;
	cin >> N >> K;
	FOR(i, 1, N) {
		char x;
		cin >> x;
		if (x == 'H')
			Hcnt++;
		else if (x == 'T')
			Tcnt++;
	}
	cout << BFS(Hcnt, Tcnt) - 1;

	return 0;
}