#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int N, M, K;
char arr[11][20];
bool visited[11][20];

bool sub_check(int y, int x, int size) {
	FOR(i, 0, size) {
		if (arr[y - i][x - i] != '*')
			return false;
		if (arr[y - i][x + i] != '*')
			return false;
	}
	return true;
}

void Make_True(int y, int x, int size) {
	FOR(i, 0, size) {
		visited[y - i][x - i] = 1;
		visited[y - i][x + i] = 1;
	}
}

void Check(int size) {
	if (size == 3)
		int a = 1;
	FOR(i, size, N) {
		FOR(j, size, M - size) {
			bool flag = sub_check(i, j, size);
			if (flag)
				Make_True(i, j, size);
		}
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		MEMSET(visited, 0);
		cin >> N >> M >> K;
		FOR(i, 1, N) {
			FOR(j, 1, M) {
				cin >> arr[i][j];
			}
		}
		FOR(i, K, min(N, (M + 1) / 2))
			Check(i);
		bool flag = true;
		FOR(i, 1, N) {
			FOR(j, 1, M) {
				if (arr[i][j] == '*' && !visited[i][j])
					flag = false;
			}
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}

	return 0;
}