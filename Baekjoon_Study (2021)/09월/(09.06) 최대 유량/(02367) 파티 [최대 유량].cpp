#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())
#define MAX 302
#define START 0
#define END 301
#define INF 987654321

int N, K, D;
vector<int> Edge[MAX];
int C[MAX][MAX] = { 0, };
int F[MAX][MAX] = { 0, };
int Prev[MAX];

int main() {
	FASTIO;
	cin >> N >> K >> D;
	FOR(i, 1, D) {
		int num;
		cin >> num;
		Edge[200 + i].push_back(END);
		C[200 + i][END] = num;
		Edge[END].push_back(200 + i);
	}
	FOR(i, 1, N) {
		int z;
		cin >> z;
		FOR(j, 1, z) {
			int num;
			cin >> num;
			Edge[i].push_back(200 + num);
			C[i][200 + num] = 1;
			Edge[200 + num].push_back(i);
		}
		Edge[START].push_back(i);
		C[START][i] = K;
		Edge[i].push_back(START);
	}
	int ans = 0;
	while (true) {
		MEMSET(Prev, -1);
		queue<int> q;
		q.push(START);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int next : Edge[cur]) {
				if (Prev[next] != -1) continue;
				if (C[cur][next] - F[cur][next] <= 0) continue;
				q.push(next);
				Prev[next] = cur;
				if (next == END)
					break;
			}
		}
		if (Prev[END] == -1)
			break;
		int mini = INF;
		for (int node = END; node != START; node = Prev[node])
			mini = min(mini, C[Prev[node]][node] - F[Prev[node]][node]);
		for (int node = END; node != START; node = Prev[node]) {
			F[Prev[node]][node] += mini;
			F[node][Prev[node]] -= mini;
		}
		ans += mini;
	}
	cout << ans;


	return 0;
}