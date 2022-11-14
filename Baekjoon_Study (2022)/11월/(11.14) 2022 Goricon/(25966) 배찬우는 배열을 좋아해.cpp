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
	vector<vector<int>> arr(N, vector<int>(M));
	vector<int> idx(N);
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> arr[i][j];
		}
		idx[i] = i;
	}
	FOR(q, 1, Q) {
		int kind, a, b, c;
		cin >> kind;
		if (kind == 0) {
			cin >> a >> b >> c;
			arr[idx[a]][b] = c;
		}
		else if (kind == 1) {
			cin >> a >> b;
			int tmp = idx[a];
			idx[a] = idx[b];
			idx[b] = tmp;
		}
	}
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cout << arr[idx[i]][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}