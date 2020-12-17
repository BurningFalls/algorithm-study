#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, K;
int arr[11];
int ans[5];
bool visited[11] = { 0, };
set<string> S;

void DFS(int cnt) {
	if (cnt == K) {
		string temp = "";
		FOR(i, 0, K - 1) {
			temp += to_string(ans[i]);
		}
		S.insert(temp);
		return;
	}
	FOR(i, 1, N) {
		if (visited[i]) continue;
		visited[i] = 1;
		ans[cnt] = arr[i];
		DFS(cnt + 1);
		visited[i] = 0;
	}
}

int main() {
	FASTIO;
	cin >> N >> K;
	FOR(i, 1, N)
		cin >> arr[i];
	DFS(0);
	cout << S.size();

	return 0;
}