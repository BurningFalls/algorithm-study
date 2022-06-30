#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 2100000000

int N;
vector<int> edge[53];
int C[53][53];
int F[53][53];
int Prev[53];
int Ans = 0;
int Start = 0, End = 25;

int Ctoi(char c) {
	if (c >= 'A' && c <= 'Z')
		return c - 'A';
	else if (c >= 'a' && c <= 'z')
		return c - 'a' + 26;
}

void BFS() {
	queue<int> q;
	q.push(Start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int next : edge[node]) {
			if (C[node][next] - F[node][next] <= 0) continue;
			if (Prev[next] != -1) continue;
			q.push(next);
			Prev[next] = node;
			if (next == End)
				break;
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		char A, B;
		int a, b, c;
		cin >> A >> B >> c;
		a = Ctoi(A); b = Ctoi(B);
		edge[a].push_back(b);
		edge[b].push_back(a);
		C[a][b] += c;
		C[b][a] += c;
	}
	
	while (true) {
		memset(Prev, -1, sizeof(Prev));
		BFS();
		if (Prev[End] == -1)
			break;
		int flow = INF;
		for (int i = End; i != Start; i = Prev[i]) {
			flow = min(flow, C[Prev[i]][i] - F[Prev[i]][i]);
		}
		for (int i = End; i != Start; i = Prev[i]) {
			F[Prev[i]][i] += flow;
			F[i][Prev[i]] -= flow;
		}
		Ans += flow;
	}
	cout << Ans;

	return 0;
}