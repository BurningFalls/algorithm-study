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

struct NODE {
	int in;
	int out;
	int visited;
	vector<int> Next;
};

map<int, NODE> mp;


void DFS(int node) {
	for (int next : mp[node].Next) {
		if (mp[next].visited == 1) {
			continue;
		}
		mp[next].visited = 1;
		DFS(next);
	}
}

int main() {
	FASTIO;
	int Case = 0;
	while (true) {
		mp.clear();
		Case++;
		bool flag = true;
		while (true) {
			vector<pii> input;
			int a, b;
			cin >> a >> b;
			if (a < 0 && b < 0) {
				return 0;
			}
			if (a == 0 && b == 0) {
				break;
			}
			input.push_back({ a, b });
			mp[a].out++;
			mp[b].in++;
			mp[a].Next.push_back(b);
		}
		int root_cnt = 0;
		int root_idx = 0;
		for (auto x : mp) {
			if (x.second.in == 0) {
				root_cnt++;
				root_idx = x.first;
			}
			else if (x.second.in != 1) {
				flag = false;
			}
		}
		if (root_cnt != 1) {
			flag = false;
		}
		if (flag) {
			mp[root_idx].visited = 1;
			DFS(root_idx);
		}
		for (auto x : mp) {
			if (x.second.visited == 0) {
				flag = false;
			}
		}
		if (mp.empty()) {
			flag = true;
		}
		cout << "Case " << Case << " ";
		cout << (flag ? "is a tree." : "is not a tree.") << "\n";
	}


	return 0;
}