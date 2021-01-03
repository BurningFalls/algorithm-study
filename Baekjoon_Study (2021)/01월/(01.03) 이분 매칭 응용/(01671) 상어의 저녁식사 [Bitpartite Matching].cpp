#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

struct Shark {
	int size;
	int speed;
	int intel;
};

int N;
Shark shark[51];
int bmatch[51] = { 0, };
bool visited[51] = { 0, };
int ans = 0;
bool wanted[51][51] = { 0, };

bool DFS(int a) {
	if (visited[a])
		return false;
	visited[a] = 1;
	FOR(b, 1, N) {
		if (!wanted[a][b]) continue;
		if (bmatch[b] == 0 || DFS(bmatch[b])) {
			bmatch[b] = a;
			return true;
		}
	}
	return false;
}

bool Compare(Shark a, Shark b) {
	if (a.size >= b.size&& a.speed >= b.speed&& a.intel >= b.intel)
		return 1;
	return 0;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		cin >> shark[i].size >> shark[i].speed >> shark[i].intel;
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (i == j) continue;
			if (wanted[j][i]) continue;
			bool flag = Compare(shark[i], shark[j]);
			if (flag)
				wanted[i][j] = 1;
		}
	}

	FOR(i, 1, N) {
		FOR(j, 1, 2) {
			memset(visited, 0, sizeof(visited));
			if (DFS(i))
				ans++;
		}
	}
	cout << N - ans;

	return 0;
}