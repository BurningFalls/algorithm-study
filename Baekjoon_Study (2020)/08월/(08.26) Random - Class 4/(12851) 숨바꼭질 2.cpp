#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N, K;
int vis = -1;
int cnt = 0;
bool visited[100001] = { 0, };

void BFS() {
	queue<pair<int, int>> q;
	q.push({ N, 0 });
	while (!q.empty()) {
		int n = q.front().first;
		int d = q.front().second;
		visited[n] = 1;
		q.pop();
		if (vis != -1 && n == K && vis == d)
			cnt++;
		if (vis == -1 && n == K) {
			vis = d;
			cnt++;
		}
		if (n - 1 >= 0 && !visited[n - 1])
			q.push({ n - 1, d + 1 });
		if (n + 1 <= 100000 && !visited[n + 1])
			q.push({ n + 1, d + 1 });
		if (n * 2 <= 100000 && !visited[n * 2])
			q.push({ n * 2, d + 1 });
	}
}

int main() {
	FASTIO;
	cin >> N >> K;
	BFS();
	cout << vis << "\n" << cnt;

	return 0;
}