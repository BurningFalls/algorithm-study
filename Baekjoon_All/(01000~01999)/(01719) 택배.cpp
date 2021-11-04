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

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<vector<int>> Graph(N + 1, vector<int>(N + 1, INF));
	vector<vector<int>> Road(N + 1, vector<int>(N + 1, 0));
	FOR(m, 1, M) {
		int a, b, c;
		cin >> a >> b >> c;
		Graph[a][b] = min(Graph[a][b], c);
		Road[a][b] = b;
		Graph[b][a] = min(Graph[b][a], c);
		Road[b][a] = a;
	}
	FOR(k, 1, N) {
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (i == j || i == k || k == j) continue;
				if (Graph[i][k] == INF || Graph[k][j] == INF) continue;
				if (Graph[i][j] > Graph[i][k] + Graph[k][j]) {
					Graph[i][j] = Graph[i][k] + Graph[k][j];
					Road[i][j] = Road[i][k];
				}
			}
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (Road[i][j] == 0) {
				cout << '-';
			}
			else {
				cout << Road[i][j];
			}
			cout << " ";
		}
		cout << "\n";
	}


	return 0;
}