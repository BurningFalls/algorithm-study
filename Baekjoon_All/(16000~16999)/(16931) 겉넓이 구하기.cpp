#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool arr[101][101][103] = { 0, };
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dx[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main() {
	FASTIO;
	int N, M;
	int ans = 0;
	int max_height = 0;
	int sum = 0;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			int num;
			cin >> num;
			max_height = max(max_height, num);
			FOR(k, 1, num)
				arr[i][j][k] = 1;
			sum += num;
		}
	}
	ans = sum * 6;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			FOR(k, 1, max_height) {
				if (!arr[i][j][k])
					break;
				FOR(t, 0, 5) {
					int ny = i + dy[t];
					int nx = j + dx[t];
					int nz = k + dz[t];
					if (ny < 1 || nx < 1 || nz < 1 ||
						ny > N || nx > M)
						continue;
					if (!arr[ny][nx][nz]) continue;
					ans--;
				}
			}
		}
	}
	cout << ans;

	return 0;
}