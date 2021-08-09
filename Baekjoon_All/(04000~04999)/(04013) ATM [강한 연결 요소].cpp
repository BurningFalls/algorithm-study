#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 500001

int N, M, S, P;
vector<int> edge[MAX];
pii arr[MAX];
int scc_num[MAX] = { 0, };
int visited[MAX] = { 0, };
int finished[MAX] = { 0, };
int scc_sum[MAX] = { 0, };
bool scc_isrest[MAX] = { 0, };
int dist[MAX] = { 0, };
int indegree[MAX] = { 0, };
int visited_idx = 0;
int scc_idx = 0;
vector<int> stored_v;
vector<int> scc_edge[MAX];

int SCC(int node) {
	visited[node] = ++visited_idx;
	stored_v.push_back(node);
	int mini = visited[node];
	for (int next : edge[node]) {
		if (!visited[next]) {
			mini = min(mini, SCC(next));
		}
		else if (!finished[next]) {
			mini = min(mini, visited[next]);
		}
	}
	if (mini == visited[node]) {
		scc_idx++;
		int sum = 0;
		bool flag = false;
		while (true) {
			int n = stored_v.back();
			stored_v.pop_back();
			finished[n] = 1;
			scc_num[n] = scc_idx;
			sum += arr[n].first;
			if (arr[n].second == 1)
				flag = true;
			if (n == node)
				break;
		}
		scc_sum[scc_idx] = sum;
		scc_isrest[scc_idx] = flag;
	}
	return mini;
}

void BFS() {
	queue<int> q;
	q.push(scc_num[S]);
	dist[scc_num[S]] = scc_sum[scc_num[S]];
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int next : scc_edge[node]) {
			if (dist[next] < dist[node] + scc_sum[next]) {
				dist[next] = dist[node] + scc_sum[next];
				q.push(next);
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
	}
	FOR(i, 1, N) {
		int num;
		cin >> num;
		arr[i] = { num, 0 };
	}
	cin >> S >> P;
	FOR(i, 1, P) {
		int num;
		cin >> num;
		arr[num].second = 1;
	}

	FOR(i, 1, N) {
		if (visited[i]) continue;
		SCC(i);
	}
	
	FOR(A, 1, N) {
		for (int B : edge[A]) {
			if (scc_num[A] == scc_num[B]) continue;
			indegree[scc_num[B]]++;
			scc_edge[scc_num[A]].push_back(scc_num[B]);
		}
	}

	BFS();

	int max_dist = 0;
	FOR(i, 1, scc_idx) {
		if (!scc_isrest[i]) continue;
		max_dist = max(max_dist, dist[i]);
	}
	cout << max_dist;

	return 0;
}