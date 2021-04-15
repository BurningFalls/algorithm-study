#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

// n번: n방과 n+1방 사이의 경계
// 1 ~ (n - 1)
bool visited[103] = { 0, };

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, M) {
		int x, y; 
		cin >> x >> y;
		FOR(j, x, y - 1)
			visited[j] = 1;
	}
	int idx = 1;
	int cnt = 0;
	while (idx <= N) {
		if (!visited[idx]) {
			cnt++;
		}
		idx++;
	}
	cout << cnt;

	return 0;
}