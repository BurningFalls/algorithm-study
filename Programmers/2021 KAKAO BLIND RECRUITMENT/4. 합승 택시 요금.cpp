#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 2100000000

int arr[201][201] = { 0, };

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			if (i == j)
				arr[i][j] = 0;
			else
				arr[i][j] = INF;
		}
	}
	int answer = 0;
	int fares_len = fares.size();
	FOR(i, 0, fares_len - 1) {
		int x = fares[i][0];
		int y = fares[i][1];
		int c = fares[i][2];
		arr[x][y] = c;
		arr[y][x] = c;
	}
	FOR(k, 1, n) {
		FOR(i, 1, n) {
			FOR(j, 1, n) {
				if (i == k || k == j || i == j) continue;
				if (arr[i][k] == INF || arr[k][j] == INF) continue;
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
	int mini = INF;
	FOR(mid, 1, n) {
		if (arr[s][mid] == INF) continue;
		if (arr[mid][a] == INF) continue;
		if (arr[mid][b] == INF) continue;
		mini = min(mini, arr[s][mid] + arr[mid][a] + arr[mid][b]);
	}
	answer = mini;

	return answer;
}

int main() {
	FASTIO;
	int n = 6, s = 4, a = 6, b = 2;
	vector<vector<int>> fares = { {4, 1, 10},{3, 5, 24},{5, 6, 2},{3, 1, 41},{5, 1, 24}, {4, 6, 50},{2, 4, 66},{2, 3, 22},{1, 6, 25} };
	cout << solution(n, s, a, b, fares);

	return 0;
}