#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

pii arr[36];
int dy[8] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int dx[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
bool visited[7][7] = { 0, };

bool func() {
	int y = arr[0].first;
	int x = arr[0].second;
	bool flag;
	visited[y][x] = 1;
	FOR(i, 1, 35) {
		flag = false;
		FOR(j, 0, 7) {
			int ny = y + dy[j];
			int nx = x + dx[j];
			if (ny < 1 || nx < 1 || ny > 6 || nx > 6) continue;
			if (visited[ny][nx]) continue;
			if (ny == arr[i].first && nx == arr[i].second) {
				flag = true;
				visited[ny][nx] = 1;
				y = ny;
				x = nx;
				break;
			}
		}
		if (!flag)
			return false;
	}
	flag = false;
	FOR(j, 0, 7) {
		int ny = y + dy[j];
		int nx = x + dx[j];
		if (ny < 1 || nx < 1 || ny > 6 || nx > 6) continue;
		if (ny == arr[0].first && nx == arr[0].second) {
			flag = true;
			visited[ny][nx] = 1;
			y = ny;
			x = nx;
			break;
		}
	}
	if (!flag)
		return false;
	return true;
}

int main() {
	FASTIO;
	FOR(i, 0, 35) {
		char a, b;
		cin >> a >> b;
		arr[i].first = a - 'A' + 1;
		arr[i].second = b - '0';
	}
	if (func())
		cout << "Valid";
	else
		cout << "Invalid";

	return 0;
}