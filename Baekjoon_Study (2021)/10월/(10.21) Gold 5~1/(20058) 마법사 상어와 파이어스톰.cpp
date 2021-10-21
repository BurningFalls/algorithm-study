#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int N, Q;
int Map[64][64];
int tmp[64][64];
int Size;
int visited[64][64] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void Rotate(int sy, int sx, int len) {
	FOR(i, 0, len - 1) {
		FOR(j, 0, len - 1) {
			tmp[sy + j][sx + len - 1 - i] = Map[sy + i][sx + j];
		}
	}
	FOR(i, 0, len - 1) {
		FOR(j, 0, len - 1) {
			Map[sy + i][sx + j] = tmp[sy + i][sx + j];
		}
	}
}

void Melting() {
	FOR(i, 0, Size - 1) {
		FOR(j, 0, Size - 1) {
			tmp[i][j] = Map[i][j];
		}
	}
	FOR(i, 0, Size - 1) {
		FOR(j, 0, Size - 1) {
			if (Map[i][j] == 0) continue;
			int cnt = 0;
			FOR(k, 0, 3) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= Size || nx >= Size) continue;
				if (tmp[ny][nx] == 0) continue;
				cnt++;
			}
			if (cnt < 3) {
				Map[i][j]--;
			}
		}
	}
}

int Counting() {
	int sum = 0;
	FOR(i, 0, Size - 1) {
		FOR(j, 0, Size - 1) {
			sum += Map[i][j];
		}
	}
	return sum;
}

int BFS(int sy, int sx) {
	int cnt = 0;
	queue<pii> q;
	visited[sy][sx] = 1;
	q.push({ sy, sx });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		cnt++;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= Size || nx >= Size) continue;
			if (Map[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
	return cnt;
}

int main() {
	FASTIO;
	cin >> N >> Q;
	Size = pow(2, N);
	FOR(i, 0, Size - 1) {
		FOR(j, 0, Size - 1) {
			cin >> Map[i][j];
		}
	}
	FOR(q, 1, Q) {
		int L;
		cin >> L;
		int tmp = pow(2, L);
		for (int i = 0; i < Size; i += tmp) {
			for (int j = 0; j < Size; j += tmp) {
				Rotate(i, j, tmp);
			}
		}
		Melting();
	}
	cout << Counting() << "\n";
	int ans = 0;
	FOR(i, 0, Size - 1) {
		FOR(j, 0, Size - 1) {
			if (Map[i][j] == 0) continue;
			if (visited[i][j]) continue;
			ans = max(ans, BFS(i, j));
		}
	}
	cout << ans;

	return 0;
}