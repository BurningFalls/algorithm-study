#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, K;
queue<int> q;
int visited[100001] = { 0, };
vector<int> v;

void BFS() {
	q.push(N);
	visited[N] = 1;
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		if (n + 1 <= 100000 && !visited[n + 1]) {
			visited[n + 1] = visited[n] + 1;
			if (n + 1 == K)
				break;
			q.push(n + 1);
		}
		if (n - 1 >= 0 && !visited[n - 1]) {
			visited[n - 1] = visited[n] + 1;
			if (n - 1 == K)
				break;
			q.push(n - 1);
		}
		if (n * 2 <= 100000 && !visited[n * 2]) {
			visited[n * 2] = visited[n] + 1;
			if (n * 2 == K)
				break;
			q.push(n * 2);
		}
	}
}

void Backtracking() {
	int pos = K;
	while (true) {
		v.push_back(pos);
		if (visited[pos] == 1)
			break;
		if (pos + 1 <= 100000 && visited[pos + 1] == visited[pos] - 1)
			pos += 1;
		else if (pos - 1 >= 0 && visited[pos - 1] == visited[pos] - 1)
			pos -= 1;
		else if (pos % 2 == 0 && visited[pos / 2] == visited[pos] - 1)
			pos /= 2;
	}
}

int main() {
	FASTIO;
	cin >> N >> K;
	BFS();
	cout << visited[K] - 1 << "\n";
	Backtracking();
	int len = v.size();
	ROF(i, len - 1, 0) {
		cout << v[i] << " ";
	}

	return 0;
}