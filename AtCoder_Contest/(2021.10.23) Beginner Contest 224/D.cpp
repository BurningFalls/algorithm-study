#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

vvi Edge(10, vi());
map<string, int> visited;

int BFS(string start) {
	string goal = "123456780";
	queue<string> q;
	q.push(start);
	visited[start] = 1;
	while (!q.empty()) {
		string cur = q.front();
		q.pop();
		if (cur == goal) {
			return visited[cur] - 1;
		}
		int empty = 0;
		FOR(i, 0, 8) {
			if (cur[i] == '0') {
				empty = i;
			}
		}
		for (int next : Edge[empty]) {
			string snext = cur;
			swap(snext[empty], snext[next]);
			if (visited.count(snext)) continue;
			visited[snext] = visited[cur] + 1;
			q.push(snext);
		}
	}
	return -1;
}

int main() {
	FASTIO;
	int M;
	cin >> M;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		a -= 1;
		b -= 1;
		Edge[a].push_back(b);
		Edge[b].push_back(a);
	}
	vi Number(10, 0);
	FOR(i, 1, 8) {
		int num;
		cin >> num;
		Number[num] = i;
	}
	string tmp = "";
	FOR(i, 1, 9) {
		char x = Number[i] + '0';
		tmp += x;
	}
	cout << BFS(tmp);

	return 0;
}