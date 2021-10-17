#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<int> indegree(N + 1, 0);
	vector<int> next(N + 1);
	FOR(i, 1, M) {
		int K;
		cin >> K;
		int prev = 0;
		FOR(j, 1, K) {
			int cur;
			cin >> cur;
			if (prev != 0) {
				next[cur] = prev;
				indegree[prev]++;
			}
			prev = cur;
		}
	}
	bool flag = true;
	FOR(i, 1, N) {
		if (indegree[i] != 0) {
			flag = false;
			break;
		}
		indegree[next[i]]--;
	}
	cout << (flag ? "Yes" : "No");

	return 0;
}