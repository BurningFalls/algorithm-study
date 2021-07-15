#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<int> v[200001];
int believe[200001] = { 0, };
int visited[200001] = { 0, };
int connection[200001] = { 0, };
queue<int> q;

void BFS() {
	while (!q.empty()) {
		int cur_node = q.front();
		q.pop();
		FOR(i, 0, connection[cur_node] - 1) {
			int next_node = v[cur_node][i];
			believe[next_node]++;
			if (visited[next_node]) continue;
			if ((connection[next_node] + 1) / 2 <= believe[next_node]) {
				visited[next_node] = visited[cur_node] + 1;
				q.push(next_node);
			}
		}
	}
}

int main() {
	FASTIO;
	int N, M;
	cin >> N;
	FOR(i, 1, N) {
		int num;
		while (true) {
			cin >> num;
			if (num == 0)
				break;
			v[i].push_back(num);
			connection[i]++;
		}
	}
	cin >> M;
	FOR(i, 1, M) {
		int num;
		cin >> num;
		visited[num] = 1;
		q.push(num);
	}
	BFS();

	FOR(i, 1, N) {
		cout << visited[i] - 1 << " ";
	}

	return 0;
}