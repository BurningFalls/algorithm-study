#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

typedef struct _INF {
	int s;
	int t;
	int cnt;
} INF;

int BFS(int ss, int st) {
	queue<INF> q;
	q.push({ ss, st, 0 });
	while (!q.empty()) {
		int s = q.front().s;
		int t = q.front().t;
		int cnt = q.front().cnt;
		q.pop();
		if (s * 2 < t + 3)
			q.push({ s * 2, t + 3, cnt + 1 });
		else if (s * 2 == t + 3)
			return cnt + 1;
		if (s + 1 < t)
			q.push({ s + 1, t, cnt + 1 });
		else if (s + 1 == t)
			return cnt + 1;
	}
	return -1;
}

int main() {
	FASTIO;
	int C;
	cin >> C;
	while (C--) {
		int S, T;
		cin >> S >> T;
		cout << BFS(S, T) << "\n";
	}

	return 0;
}