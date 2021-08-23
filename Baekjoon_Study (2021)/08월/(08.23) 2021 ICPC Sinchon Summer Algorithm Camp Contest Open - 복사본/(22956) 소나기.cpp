#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

typedef struct _NODE {
	int height;
	int water;
	int timing;
} NODE;

int N, M, Q;
NODE Map[1001][1001];
pii Parent[1001][1001];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

pii Find_Parent(pii node) {
	if (Parent[node.first][node.second] == node)
		return node;
	return Parent[node.first][node.second] = Find_Parent(Parent[node.first][node.second]);
}

void Union(pii n1, pii n2) {
	n1 = Find_Parent(n1);
	n2 = Find_Parent(n2);
	NODE N1 = Map[n1.first][n1.second];
	NODE N2 = Map[n2.first][n2.second];
	if (N1.height == N2.height) {
		if (N1.timing < N2.timing)
			Parent[n2.first][n2.second] = n1;
		else
			Parent[n1.first][n1.second] = n2;
	}
	else if (N1.height < N2.height)
		Parent[n2.first][n2.second] = n1;
	else
		Parent[n1.first][n1.second] = n2;
}

int main() {
	FASTIO;
	cin >> N >> M >> Q;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			Parent[i][j] = { i, j };
			int num;
			cin >> num;
			Map[i][j] = { num, 0, 0 };
		}
	}
	FOR(q, 1, Q) {
		if (q == Q) {
			int yy = 1;
		}
		int y, x, c;
		cin >> y >> x >> c;
		pii tmp = Find_Parent({ y, x });
		Map[y][x] = { Map[y][x].height - c, Map[y][x].water + c, q };
		Parent[y][x] = { y, x };
		Union(tmp, { y, x });
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (Map[ny][nx].water == 0) continue;
			Union({ y, x }, { ny, nx });
		}
		pii pos = Find_Parent({ y, x });
		cout << pos.first << " " << pos.second << "\n";
	}


	return 0;
}