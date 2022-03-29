#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int L, N;
vector<string> v(20);
vector<bool> visited(20, 0);
vector<string> ans(20);

void DFS(int cnt) {
	if (cnt == L) {
		bool flag = true;
		FOR(i, 0, L - 1) {
			FOR(j, i + 1, L - 1) {
				flag &= (ans[i][j] == ans[j][i]);
			}
		}
		if (flag) {
			FOR(i, 0, L - 1) {
				FOR(j, 0, L - 1) {
					cout << ans[i][j];
				}
				cout << "\n";
			}
			exit(0);
		}
		return;
	}
	FOR(i, 0, N - 1) {
		if (visited[i]) continue;
		visited[i] = 1;
		ans[cnt] = v[i];
		DFS(cnt + 1);
		visited[i] = 0;
	}
}

int main() {
	FASTIO;
	cin >> L >> N;
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}
	sort(v.begin(), v.begin() + N);
	DFS(0);
	cout << "NONE";

	return 0;
}