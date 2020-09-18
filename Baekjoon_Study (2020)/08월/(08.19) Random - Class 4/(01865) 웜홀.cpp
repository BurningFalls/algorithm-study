#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 987654321
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int TC;
	cin >> TC;
	while (TC--) {
		vector<pair<int, int>> v[501];
		int arr[501];
		int N, M, W;
		int cnt = 0;
		bool flag = true;
		cin >> N >> M >> W;
		FOR(i, 2, N)
			arr[i] = INF;
		arr[1] = 0;
		int S, E, T;
		FOR(i, 1, M) {
			cin >> S >> E >> T;
			v[S].push_back(make_pair(E, T));
			v[E].push_back(make_pair(S, T));
		}
		FOR(i, 1, W) {
			cin >> S >> E >> T;
			v[S].push_back(make_pair(E, -T));
		}
		while(flag && cnt != N) {
			flag = false;
			cnt++;
			FOR(i, 1, N) {
				int len = v[i].size();
				FOR(j, 0, len - 1) {
					int n = v[i][j].first;
					int d = v[i][j].second;
					if (arr[n] > arr[i] + d) {
						arr[n] = arr[i] + d;
						flag = true;
					}
				}
			}
		}
		if (cnt == N)
			cout << "YES";
		else
			cout << "NO";
		cout << "\n";
	}

	return 0;
}