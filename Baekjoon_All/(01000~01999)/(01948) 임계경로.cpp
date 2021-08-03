#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
int Start, End;
vector<pii> edge[10001];
int indegree[10001] = { 0, };
vector<int> max_road[10001];
int dist[10001] = { 0, };
bool visited[10001] = { 0, };

void TS() {
	queue<int> q;
	q.push(Start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		int len = edge[node].size();
		FOR(i, 0, len - 1) {
			int next = edge[node][i].first;
			int cost = edge[node][i].second;
			indegree[next]--;
			if (indegree[next] == 0)
				q.push(next);
			if (dist[next] <= dist[node] + cost) {
				if (dist[next] != dist[node] + cost)
					max_road[next].clear();
				dist[next] = dist[node] + cost;
				max_road[next].push_back(node);
			}
		}
	}
}

int BFS() {
	queue<int> q;
	int cnt = 0;
	q.push(End);
	visited[End] = 1;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		int len = max_road[node].size();
		FOR(i, 0, len - 1) {
			int next = max_road[node][i];
			cnt++;
			if (visited[next]) continue;
			visited[next] = 1;
			q.push(next);
		}
	}
	return cnt;
}

int main() {
	FASTIO;
	int max_length = 0;
	cin >> N >> M;
	FOR(i, 1, M) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
		indegree[b]++;
	}
	cin >> Start >> End;
	TS();
	FOR(i, 1, N)
		max_length = max(max_length, dist[i]);
	cout << max_length << "\n";
	cout << BFS();

	return 0;
}