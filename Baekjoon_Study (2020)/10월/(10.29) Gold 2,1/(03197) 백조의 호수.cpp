#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int R, C;
char Map[1502][1502];
int group[1502][1502] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
queue<pii> edge_q;
int Parent[1500 * 1500 + 1];
vector<int> swan_v;

int Find_Parent(int node) {
	if (Parent[node] == node)
		return node;
	return Parent[node] = Find_Parent(Parent[node]);
}

bool is_Same(int n1, int n2) {
	n1 = Find_Parent(n1);
	n2 = Find_Parent(n2);
	return n1 == n2;
}

void Union(int n1, int n2) {
	n1 = Find_Parent(n1);
	n2 = Find_Parent(n2);
	Parent[n2] = n1;
}

void Grouping(int sy, int sx, int idx) {
	queue<pii> q;
	q.push({ sy, sx });
	group[sy][sx] = idx;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (Map[y][x] == 'L')
			swan_v.push_back(idx);
		bool flag = false;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
			if (Map[ny][nx] == 'X')
				flag = true;
			if (group[ny][nx]) continue;
			group[ny][nx] = idx;
			q.push({ ny, nx });
		}
		if (flag) {
			edge_q.push({ y, x });
		}
	}
}

bool Melting() {
	int len = edge_q.size();
	FOR(i, 1, len) {
		int y = edge_q.front().first;
		int x = edge_q.front().second;
		edge_q.pop();
		FOR(j, 0, 3) {
			int ny = y + dy[j];
			int nx = x + dx[j];
			if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
			if (group[ny][nx] == -1) {
				group[ny][nx] = group[y][x];
				edge_q.push({ ny, nx });
				FOR(k, 0, 3) {
					int nny = ny + dy[k];
					int nnx = nx + dx[k];
					if (nny < 1 || nnx < 1 || nny > R || nnx > C) continue;
					if (group[nny][nnx] == -1) continue;
					if (group[nny][nnx] == group[ny][nx]) continue;
					int a = group[ny][nx];
					int b = group[nny][nnx];
					if (!is_Same(a, b)) {
						Union(a, b);
						if (is_Same(swan_v[0], swan_v[1]))
							return true;
					}
				}
			}
		}
	}
	return false;
}

void Print() {
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			if (group[i][j] == -1)
				cout << 0;
			else
				cout << group[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

void Print_Parent(int grp) {
	FOR(i, 1, grp) {
		cout << Find_Parent(i) << " ";
	}
	cout << "\n";
}

int main() {
	FASTIO;
	cin >> R >> C;
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cin >> Map[i][j];
			if (Map[i][j] == 'X')
				group[i][j] = -1;
		}
	}
	int grp = 0;
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			if (group[i][j] == 0) {
				grp++;
				Grouping(i, j, grp);
			}
		}
	}
	FOR(i, 1, grp)
		Parent[i] = i;

	int day = 1;
	while (!Melting()) {
		day++;
	}
	cout << day;

	return 0;
}