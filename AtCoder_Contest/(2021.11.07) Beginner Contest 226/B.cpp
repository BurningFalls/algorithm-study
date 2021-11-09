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

set<vector<int>> s;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int L;
		cin >> L;
		vector<int> tmp;
		FOR(j, 1, L) {
			int num;
			cin >> num;
			tmp.push_back(num);
		}
		s.insert(tmp);
	}
	cout << LEN(s);

	return 0;
}