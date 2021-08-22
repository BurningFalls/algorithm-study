#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

queue<pii> q;

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N) {
		FOR(j, 1, K) {
			int num;
			cin >> num;
			q.push({ num, i });
		}
	}
	int len = q.size();
	while (len != 1) {
		int node = q.front().first;
		q.pop();
		len--;
		node = (node - 1) % len;
		FOR(i, 1, node) {
			q.push(q.front());
			q.pop();
		}
	}
	cout << q.front().second << " " << q.front().first;

	return 0;
}