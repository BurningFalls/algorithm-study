#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	int Z;
	cin >> Z;
	while (Z--) {
		int N, M;
		cin >> N >> M;
		vector<int> t(M + 1);
		PQ<int, vector<int>, greater<int>> pq;
		vector<bool> lake(N + 1, 1);
		vector<int> idx(M + 1, 0);
		vector<int> next_idx(M + 1, 0);
		vector<bool> check(N + 1, 0);
		FOR(i, 1, M) {
			cin >> t[i];
			if (t[i] == 0) continue;
			if (check[t[i]]) continue;
			check[t[i]] = 1;
			pq.push(i);
		}
		ROF(i, M, 1) {
			if (t[i] == 0) continue;
			if (idx[t[i]] != 0) {
				next_idx[i] = idx[t[i]];
			}
			idx[t[i]] = i;
		}
		bool flag = true;
		vector<int> ans;
		FOR(i, 1, M) {
			if (t[i] == 0) {
				if (!pq.empty()) {
					lake[t[pq.top()]] = 0;
					ans.push_back(t[pq.top()]);
					pq.pop();
				}
				else {
					ans.push_back(0);
				}
			}
			else {
				if (lake[t[i]] == 1) {
					flag = false;
					break;
				}
				else if (lake[t[i]] == 0) {
					lake[t[i]] = 1;
					if (next_idx[i] != 0) {
						pq.push(next_idx[i]);
					}
				}
			}
		}
		if (flag) {
			cout << "YES\n";
			for (int x : ans) {
				cout << x << " ";
			}
		}
		else if (!flag) {
			cout << "NO";
		}
		cout << "\n";
	}

	return 0;
}