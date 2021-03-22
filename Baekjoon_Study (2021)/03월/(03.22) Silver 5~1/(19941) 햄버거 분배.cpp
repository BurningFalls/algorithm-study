#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,A,B) int a = A; int b = B; for(int i=(a);i<=(b);i++)
#define ROF(i,A,B) int a = A; int b = B; for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool visited[20001] = { 0, };

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	string s;
	cin >> s;
	int cnt = 0;
	FOR(i, 0, N - 1) {
		if (s[i] != 'P') continue;
		FOR(j, max(0, i - K), min(N - 1, i + K)) {
			if (s[j] == 'H') {
				if (visited[j]) continue;
				visited[j] = 1;
				cnt++;
				break;
			}
		}
	}
	cout << cnt;

	return 0;
}