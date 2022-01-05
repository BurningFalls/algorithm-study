#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

bool Check(vector<int>&v) {
	FOR(i, 1, 10) {
		if (v[i] != 1)
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<vector<char>> Map(N, vector<char>(M));
	vector<pii> one;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
			if (Map[i][j] == '1') {
				one.push_back({ i, j });
			}
		}
	}
	int ay = -1, ax = -1;
	for (pii node : one) {
		int y = node.first;
		int x = node.second;
		vector<int> check(11, 0);
		FOR(i, max(0, y - 9), min(N - 1, y + 9)) {
			FOR(j, max(0, x - 9), min(M - 1, x + 9)) {
				if (Map[i][j] == '0') continue;
				int score = 10 - max(abs(i - y), abs(j - x));
				check[score]++;
			}
		}
		if (Check(check)) {
			ay = y;
			ax = x;
			break;
		}
	}
	if (ay == -1 && ax == -1) {
		cout << -1;
	}
	else {
		cout << ay << " " << ax;
	}

	return 0;
}