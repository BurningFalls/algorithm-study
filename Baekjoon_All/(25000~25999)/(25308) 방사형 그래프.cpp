#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

vector<double> a(8);
vector<double> v(8);
vector<bool> visited(8, 0);
int ans = 0;

bool Check() {
	FOR(i, 0, 7) {
		int a = i;
		int b = (i + 1) % 8;
		int c = (i + 2) % 8;
		if (v[a] * v[c] * sqrt(2) > v[b] * (v[a] + v[c])) {
			return false;
		}
	}
	return true;
}

void DFS(int cnt) {
	if (cnt == 8) {
		ans += Check();
		return;
	}
	FOR(i, 0, 7) {
		if (visited[i]) continue;
		visited[i] = 1;
		v[cnt] = a[i];
		DFS(cnt + 1);
		visited[i] = 0;
	}
}

int main() {
	FASTIO;
	FOR(i, 0, 7) {
		cin >> a[i];
	}
	DFS(0);
	cout << ans;

	return 0;
}