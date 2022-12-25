#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int N;
vector<vector<char>> v(3073, vector<char>(6145, ' '));

void DFS(int n, int y, int x) {
	if (n == 3) {
		v[y][x] = '*';
		v[y + 1][x - 1] = '*';
		v[y + 1][x + 1] = '*';
		FOR(i, x - 2, x + 2) {
			v[y + 2][i] = '*';
		}
		return;
	}
	DFS(n / 2, y, x);
	DFS(n / 2, y + n / 2, x - n / 2);
	DFS(n / 2, y + n / 2, x + n / 2);
}

int main() {
	FASTIO;
	cin >> N;

	DFS(N, 0, N - 1);

	FOR(i, 0, N - 1) {
		FOR(j, 0, N * 2 - 1) {
			cout << v[i][j];
		}
		cout << "\n";
	}

	return 0;
}