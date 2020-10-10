#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
vector<pair<pair<int, int>, int>> v;
vector<int> edge[3001];
bool visited[3001];

int Dist(pii a, pii b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void DFS(int node) {
	int len = edge[node].size();
	FOR(i, 0, len - 1) {
		int nn = edge[node][i];
		if (visited[nn]) continue;
		visited[nn] = 1;
		DFS(nn);
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		v.clear();
		FOR(i, 0, N - 1) {
			edge[i].clear();
			visited[i] = 0;
		}
		FOR(i, 0, N - 1) {
			int x, y, R;
			cin >> x >> y >> R;
			v.push_back({ { x, y }, R });
		}
		FOR(i, 0, N - 1) {
			FOR(j, i + 1, N - 1) {
				int temp1 = Dist(v[i].first, v[j].first);
				int temp2 = (v[i].second + v[j].second) * (v[i].second + v[j].second);
				if (temp1 <= temp2) {
					edge[i].push_back(j);
					edge[j].push_back(i);
				}
			}
		}
		int cnt = 0;
		FOR(i, 0, N - 1) {
			if (visited[i]) continue;
			cnt++;
			visited[i] = 1;
			DFS(i);
		}
		cout << cnt << "\n";
	}

	return 0;
}