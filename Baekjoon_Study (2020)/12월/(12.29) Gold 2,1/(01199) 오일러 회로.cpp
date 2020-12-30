#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int Graph[1001][1001];
int conn[1001] = { 0, };

void DFS(int node) {
	FOR(i, 1, N) {
		while (Graph[node][i]) {
			Graph[node][i]--;
			Graph[i][node]--;
			DFS(i);
		}
	}
	cout << node << " ";
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Graph[i][j];
			conn[i] += Graph[i][j];
			conn[j] += Graph[i][j];
		}
	}
	FOR(i, 1, N)
		conn[i] /= 2;
	bool flag = true;
	FOR(i, 1, N) {
		if (conn[i] % 2 == 1) {
			flag = false;
			break;
		}
	}
	if (!flag)
		cout << -1;
	else {
		DFS(1);
	}


	return 0;
}