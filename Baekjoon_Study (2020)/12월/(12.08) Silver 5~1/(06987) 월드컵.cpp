#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int choose[2];
vector<pii> v;
int arr[4][7][4];
int ans[7][4] = { 0, };
bool result[4] = { 0, };

void Check() {
	FOR(k, 0, 3) {
		bool flag = true;
		FOR(i, 1, 6) {
			FOR(j, 1, 3) {
				if (ans[i][j] != arr[k][i][j]) {
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
		}
		if (flag) {
			result[k] = 1;
		}
	}
}

void dfs(int node, int cnt) {
	if (cnt == 2) {
		v.push_back({ choose[0], choose[1] });
		return;
	}
	FOR(i, node, 6) {
		choose[cnt] = i;
		dfs(i + 1, cnt + 1);
	}
}

void DFS(int cnt) {
	if (cnt == 15) {
		Check();
		return;
	}
	int t1 = v[cnt].first;
	int t2 = v[cnt].second;

	ans[t1][1]++;
	ans[t2][3]++;
	DFS(cnt + 1);
	ans[t1][1]--;
	ans[t2][3]--;

	ans[t1][3]++;
	ans[t2][1]++;
	DFS(cnt + 1);
	ans[t1][3]--;
	ans[t2][1]--;

	ans[t1][2]++;
	ans[t2][2]++;
	DFS(cnt + 1);
	ans[t1][2]--;
	ans[t2][2]--;
}

int main() {
	FASTIO;
	FOR(k, 0, 3) {
		FOR(i, 1, 6) {
			FOR(j, 1, 3) {
				cin >> arr[k][i][j];
			}
		}
	}
	dfs(1, 0);
	DFS(0);
	FOR(i, 0, 3)
		cout << result[i] << " ";

	return 0;
}