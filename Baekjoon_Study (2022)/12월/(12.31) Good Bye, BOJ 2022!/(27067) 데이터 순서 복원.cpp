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
#define MAX 3001

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<vector<int>> pos(MAX, vector<int>());
	vector<int> ans(MAX, 0);
	FOR(i, 0, 2) {
		FOR(j, 0, N - 1) {
			int num;
			cin >> num;
			pos[num].push_back(j);
		}
	}

	map<int, vector<int>> mp;
	FOR(i, 1, N) {
		sort(ALL(pos[i]));
		int a = pos[i][0], b = pos[i][1], c = pos[i][2];
		if (a == b && b + 1 == c) {
			ans[a] = i;
		}
		else if (a != b && b != c) {
			ans[b] = i;
		}
		else if (a == b && b == c) {
			if (a == 0) {
				ans[a] = i;
			}
			else {
				mp[i].push_back(a - 1);
				mp[i].push_back(a);
			}
		}
		else if (a + 1 == b && b == c) {
			mp[i].push_back(a);
			mp[i].push_back(b);
		}
		else if (a + 1 < b && b == c) {
			mp[i].push_back(b - 1);
			mp[i].push_back(b);
		}
	}

	bool flag = true;
	while (flag) {
		flag = false;
		for (const auto& x : mp) {
			int t1 = x.second[0];
			int t2 = x.second[1];
			if (ans[t1] != 0 && ans[t2] == 0) {
				ans[t2] = x.first;
				flag = true;
			}
			else if (ans[t1] == 0 && ans[t2] != 0) {
				ans[t1] = x.first;
				flag = true;
			}
		}
	}

	FOR(i, 0, N - 1) {
		cout << ans[i] << " ";
	}


	return 0;
}