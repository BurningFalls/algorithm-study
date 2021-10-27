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

string BFS(int s, int t) {
	queue<int> q;
	map<int, string> visited;
	visited[s] = "";
	q.push(s);
	while (!q.empty()) {
		ll node = q.front();
		q.pop();
		if (node == t) {
			return visited[node];
		}
		ll next1 = node * 2;
		ll next2 = node * node;
		if (next2 <= t && !visited.count(next2)) {
			visited[next2] = visited[node] + '*';
			q.push(next2);
		}
		if (next1 <= t && !visited.count(next1)) {
			visited[next1] = visited[node] + '+';
			q.push(next1);
		}
	}
	return "-1";
}

int main() {
	FASTIO;
	int s, t;
	cin >> s >> t;
	if (s == t) {
		cout << 0;
		return 0;
	}
	string t1 = BFS(s, t);
	string t2 = BFS(1, t);
	if (t1 == "-1" && t2 == "-1") {
		cout << -1;
	}
	else if (t1 == "-1") {
		cout << '/' << t2;
	}
	else if (t2 == "-1") {
		cout << t1;
	}
	else {
		if (LEN(t1) <= LEN(t2) + 1) {
			cout << t1;
		}
		else {
			cout << '/' << t2;
		}
	}

	return 0;
}