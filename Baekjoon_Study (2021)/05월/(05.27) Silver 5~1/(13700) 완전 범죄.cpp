#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, S, D, F, B, K;

int road[100001] = { 0, };

int BFS() {
	queue<int> q;
	road[S] = 1;
	q.push(S);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (node == D)
			return road[node];
		if (node + F <= N && road[node + F] == 0) {
			road[node + F] = road[node] + 1;
			q.push(node + F);
		}
		if (node - B >= 1 && road[node - B] == 0) {
			road[node - B] = road[node] + 1;
			q.push(node - B);
		}
	}
	return 0;
}

int main() {
	FASTIO;
	cin >> N >> S >> D >> F >> B >> K;
	FOR(i, 1, K) {
		int num;
		cin >> num;
		road[num] = -1;
	}
	int tmp = BFS();
	if (tmp == 0)
		cout << "BUG FOUND";
	else
		cout << tmp - 1;

	return 0;
}