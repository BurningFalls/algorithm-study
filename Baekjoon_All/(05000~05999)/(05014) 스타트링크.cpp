#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int F, S, G, U, D;
queue<int> q;
int visited[1000001] = { 0, };

void BFS() {
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		if (n == G)
			break;
		if (n + U <= F && !visited[n + U]) {
			visited[n + U] = visited[n] + 1;
			q.push(n + U);
		}
		if (n - D >= 1 && !visited[n - D]) {
			visited[n - D] = visited[n] + 1;
			q.push(n - D);
		}
	}
}

int main() {
	FASTIO;
	cin >> F >> S >> G >> U >> D;
	q.push(S);
	visited[S] = 1;
	BFS();
	if (visited[G] == 0)
		cout << "use the stairs";
	else
		cout << visited[G] - 1;

	return 0;
}