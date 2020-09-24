#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 987654321

bool is_Prime[10000] = { 0, };
int visited[10000];

bool Prime_Check(int num) {
	FOR(i, 2, sqrt(num)) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int BFS(int start, int end, int cnt) {
	queue<int> q;
	if (start == end)
		return 0;
	string goal = to_string(end);
	visited[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		string s = to_string(n);
		string temp;
		FOR(i, 0, 3) {
			temp = s;
			FOR(j, 0, 9) {
				if (i == 0 && j == 0) continue;
				temp[i] = j + '0';
				int x = stoi(temp);
				if (visited[x]) continue;
				visited[x] = visited[n] + 1;
				if (x == end)
					return visited[x] - 1;
				if (is_Prime[x])
					q.push(x);
			}
		}
	}
	return -1;
}

int main() {
	FASTIO;
	FOR(i, 1000, 9999) {
		if (Prime_Check(i))
			is_Prime[i] = 1;
	}
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		FOR(i, 1000, 9999)
			visited[i] = 0;
		cin >> a >> b;
		int flag = BFS(a, b, 0);
		if (flag == -1)
			cout << "Impossible";
		else
			cout << flag;
		cout << "\n";
	}

	return 0;
}