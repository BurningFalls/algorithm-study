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
	int N;
	cin >> N;
	vector<int> W(N);
	vector<vector<int>> pos(1000001, vector<int>());
	FOR(i, 0, N - 1) {
		cin >> W[i];
		pos[W[i]].push_back(i);
	}
	int ans = 0;
	int posit = N;
	ROF(i, 1000000, 1) {
		bool flag = false;
		while (!pos[i].empty()) {
			int x = pos[i].back();
			pos[i].pop_back();
			if (x <= posit) {
				posit = x;
				ans++;
			}
			else {
				flag = true;
			}
		}
		if (flag) break;
	}
	cout << N - ans;

	return 0;
}