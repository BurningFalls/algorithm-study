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
	vvi Edge(N + 1, vi());
	vi Color(N + 1, 1);
	vi Indegree(N + 1, 0);
	vector<set<int>> Exist(N + 1);
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		Edge[min(a, b)].push_back(max(a, b));
	}
	FOR(i, 1, N) {
		int num = 1;
		for (auto it = Exist[i].begin(); it != Exist[i].end(); it++) {
			if (num != (*it)) {
				break;
			}
			else {
				num++;
			}
		}
		Color[i] = num;
		for (int next : Edge[i]) {
			Exist[next].insert(num);
		}
	}
	FOR(i, 1, N) {
		cout << Color[i] << " ";
	}


	return 0;
}