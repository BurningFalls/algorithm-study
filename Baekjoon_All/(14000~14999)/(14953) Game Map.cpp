#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
vector<int> v[100001];
int cnt[100001] = { 0, };
int dist[100001];
bool visited[100001] = { 0, };

int DFS(int cur) {
	int& ret = dist[cur];
	if (ret != -1)
		return ret;
	ret = 1;
	for (int next : v[cur]) {
		if (cnt[cur] >= cnt[next]) continue;
		if (visited[next]) continue;
		visited[next] = 1;
		ret = max(ret, DFS(next) + 1);
		visited[next] = 0;
	}
	return ret;
}


int main() {
	FASTIO;
	memset(dist, -1, sizeof(dist));
	cin >> N >> M;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		v[a + 1].push_back(b + 1);
		v[b + 1].push_back(a + 1);
		cnt[a + 1]++;
		cnt[b + 1]++;
	}
	FOR(i, 1, N) {
		visited[i] = 1;
		DFS(i);
		visited[i] = 0;
	}
	int maxi = 0;
	FOR(i, 1, N) {
		maxi = max(maxi, dist[i]);
	}
	cout << maxi;

	return 0;
}