#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

bool visited[10001];
string ord[10001];

void BFS(int s, int e) {
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	ord[s] = "";
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		int temp;
		temp = (n * 2) % 10000;
		if (!visited[temp]) {
			ord[temp] = ord[n] + 'D';
			if (temp == e)
				break;
			visited[temp] = 1;
			q.push(temp);
		}
		if (n == 0)
			temp = 9999;
		else
			temp = n - 1;
		if (!visited[temp]) {
			ord[temp] = ord[n] + 'S';
			if (temp == e)
				break;
			visited[temp] = 1;
			q.push(temp);
		}
		int len = to_string(n).size();
		temp = (n % 1000) * 10 + n / 1000;
		if (!visited[temp]) {
			ord[temp] = ord[n] + 'L';
			if (temp == e)
				break;
			visited[temp] = 1;
			q.push(temp);
		}
		temp = (n / 10) + (n % 10) * 1000;
		if (!visited[temp]) {
			ord[temp] = ord[n] + 'R';
			if (temp == e)
				break;
			visited[temp] = 1;
			q.push(temp);
		}
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		memset(visited, 0, sizeof(visited));
		int A, B;
		cin >> A >> B;
		BFS(A, B);
		cout << ord[B] << "\n";
	}

	return 0;
}