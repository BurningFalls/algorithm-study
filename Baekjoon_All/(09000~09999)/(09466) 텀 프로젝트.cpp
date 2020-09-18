#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int num[100001];
bool visited[100001];
bool impossible[100001];
int cnt;

void DFS(int node) {
	visited[node] = 1;
	int new_node = num[node];
	if (!visited[new_node])
		DFS(new_node);
	else {
		if (!impossible[new_node]) {
			int idx = new_node;
			while (idx != node) {
				cnt++;
				idx = num[idx];
			}
			cnt++;
		}
	}
	impossible[node] = 1;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cnt = 0;
		cin >> N;
		FOR(i, 1, N) {
			visited[i] = 0;
			impossible[i] = 0;
		}
		FOR(i, 1, N)
			cin >> num[i];
		FOR(i, 1, N) {
			if (visited[i]) continue;
			DFS(i);
		}
		cout << N - cnt << "\n";
	}

	return 0;
}