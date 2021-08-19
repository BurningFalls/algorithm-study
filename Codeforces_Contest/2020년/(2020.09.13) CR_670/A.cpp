#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		int visited[102] = { 0, };
		int ans = 0;
		int num;
		cin >> N;
		FOR(i, 1, N) {
			cin >> num;
			visited[num]++;
		}
		int idx = 0;
		while (visited[idx] != 0) {
			visited[idx]--;
			idx++;
		}
		ans += idx;
		idx = 0;
		while (visited[idx] != 0) {
			visited[idx]--;
			idx++;
		}
		ans += idx;
		cout << ans << "\n";
	}

	return 0;
}