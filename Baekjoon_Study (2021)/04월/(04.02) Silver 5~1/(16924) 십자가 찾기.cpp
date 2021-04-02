#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char Map[101][101];
bool check[101][101] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

struct INF {
	int y;
	int x;
	int s;
};

vector<INF> v;

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	FOR(i, 2, N - 1) {
		FOR(j, 2, M - 1) {
			if (Map[i][j] == '.') continue;
			bool con_flag = true;
			int idx = 1;
			while (con_flag) {
				int flag = 0;
				FOR(k, 0, 3) {
					int ny = i + dy[k] * idx;
					int nx = j + dx[k] * idx;
					if (ny < 1 || nx < 1 || ny > N || nx > M) break;
					if (Map[ny][nx] == '.') break;
					flag++;
				}
				if (flag == 4) {
					v.push_back({ i, j, idx });
					check[i][j] = 1;
					FOR(k, 0, 3) {
						int ny = i + dy[k] * idx;
						int nx = j + dx[k] * idx;
						check[ny][nx] = 1;
					}
				}
				else
					con_flag = false;
				idx++;
			}
		}
	}
	bool use_flag = true;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (Map[i][j] == '*' && check[i][j] == 0) {
				use_flag = false;
				break;
			}
		}
	}
	if (!use_flag) {
		cout << -1;
		return 0;
	}
	int len = v.size();
	cout << len << "\n";
	for (INF n : v) {
		cout << n.y << " " << n.x << " " << n.s << "\n";
	}


	return 0;
}