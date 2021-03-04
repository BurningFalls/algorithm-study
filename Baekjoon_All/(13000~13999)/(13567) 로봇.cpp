#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int M, n;
int y = 0, x = 0;
int dir = 0;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1,  0 };
vector<pair<string, int>> v;

bool Move() {
	FOR(i, 0, n - 1) {
		string order = v[i].first;
		int num = v[i].second;
		if (order == "MOVE") {
			y += dy[dir] * num;
			x += dx[dir] * num;
			if (y < 0 || x < 0 || y > M || x > M)
				return false;
		}
		else if (order == "TURN") {
			if (num == 0)
				dir = (dir + 1) % 4;
			else if (num == 1)
				dir = (dir + 3) % 4;
		}
	}
	return true;
}

int main() {
	FASTIO;
	cin >> M >> n;
	FOR(i, 1, n) {
		string order;
		int num;
		cin >> order >> num;
		v.push_back({ order, num });
	}

	if (Move())
		cout << x << " " << y;
	else
		cout << -1;

	return 0;
}