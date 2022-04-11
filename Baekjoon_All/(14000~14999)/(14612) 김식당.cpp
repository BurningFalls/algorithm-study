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

bool compare(pii a, pii b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<pii> v;
	FOR(i, 1, N) {
		string s;
		int n, t;
		cin >> s;
		if (s == "order") {
			cin >> n >> t;
			v.push_back({ n, t });
		}
		else if (s == "sort") {
			sort(ALL(v), compare);
		}
		else if (s == "complete") {
			cin >> n;
			FOR(j, 0, LEN(v) - 1) {
				if (v[j].first == n) {
					v.erase(v.begin() + j);
				}
			}
		}
		if (v.empty()) {
			cout << "sleep";
		}
		else {
			for (pii x : v) {
				cout << x.first << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}