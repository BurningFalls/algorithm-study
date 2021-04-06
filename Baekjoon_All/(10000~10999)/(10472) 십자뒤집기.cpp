#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int visited[1 << 9] = { 0, };
vector<int> flap;

void Make_flap() {
	int dy[5] = { -1, 1, 0, 0, 0 };
	int dx[5] = { 0 ,0, -1, 1, 0 };
	int arr[3][3] = { {8, 7, 6}, {5, 4, 3}, {2, 1, 0} };
	FOR(i, 0, 2) {
		FOR(j, 0, 2) {
			int sum = 0;
			FOR(k, 0, 4) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny > 2 || nx > 2) continue;
				sum += pow(2, arr[ny][nx]);
			}
			flap.push_back(sum);
		}
	}
}

void BFS() {
	queue<int> q;
	q.push(0);
	visited[0] = 1;
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		FOR(i, 0, 8) {
			int nn = (n ^ flap[i]);
			if (visited[nn]) continue;
			visited[nn] = visited[n] + 1;
			q.push(nn);
		}
	}
}

int main() {
	FASTIO;
	Make_flap();
	BFS();
	int T;
	cin >> T;
	while (T--) {
		int sum = 0;
		FOR(i, 0, 8) {
			char x;
			cin >> x;
			if (x == '*')
				sum += pow(2, 8 - i);
		}
		cout << visited[sum] - 1 << "\n";
	}


	return 0;
}