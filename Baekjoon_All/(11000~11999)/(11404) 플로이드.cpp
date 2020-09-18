#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int main() {
	int N, M;
	int cost[101][101];
	int a, b, c;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			cost[i][j] = INF;
		}
	}
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		cost[a][b] = min(cost[a][b], c);
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j || i == k || j == k) continue;
				if (cost[i][k] == INF || cost[k][j] == INF) continue;
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (cost[i][j] == INF)
				cost[i][j] = 0;
			cout << cost[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}