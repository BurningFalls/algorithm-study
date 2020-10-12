#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

queue<int> q;
map<int, int> visited;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int BFS() {
	while (!q.empty()) {
		int n = q.front();
		string s = to_string(n);
		q.pop();
		if (n == 123456789)
			return visited[123456789];
		int zero_pos = s.find('9');
		int y = zero_pos / 3;
		int x = zero_pos % 3;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= 3 || nx >= 3) continue;
			string temp = s;
			swap(temp[y * 3 + x], temp[ny * 3 + nx]);
			int nn = stoi(temp);
			if (visited.count(nn)) continue;
			visited[nn] = visited[n] + 1;
			q.push(nn);
		}
	}
	return 0;
}

int main() {
	FASTIO;
	int num = 0;
	int n;
	ROF(i, 8, 0) {
		cin >> n;
		if (n == 0)
			n = 9;
		num += n * pow(10, i);
	}
	q.push(num);
	visited[num] = 1;
	cout << BFS() - 1;

	return 0;
}