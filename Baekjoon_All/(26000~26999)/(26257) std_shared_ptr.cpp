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

int main() {
	FASTIO;
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<int> object(M + 1);
	FOR(i, 1, M) {
		cin >> object[i];
	}
	FOR(i, 1, Q) {
		string s;
		int x, y;
		cin >> s;
		if (s == "assign") {
			cin >> x >> y;
			object[x] = object[y];
		}
		else if (s == "swap") {
			cin >> x >> y;
			swap(object[x], object[y]);
		}
		else if (s == "reset") {
			cin >> x;
			object[x] = 0;
		}
	}

	vector<bool> visited(N + 1, 0);
	FOR(i, 1, M) {
		if (object[i] == 0) continue;
		visited[object[i]] = 1;
	}

	int cnt = 0;
	FOR(i, 1, N) {
		cnt += visited[i];
	}

	cout << cnt << "\n";
	FOR(i, 1, N) {
		if (visited[i] == 0) continue;
		cout << i << "\n";
	}

	return 0;
}