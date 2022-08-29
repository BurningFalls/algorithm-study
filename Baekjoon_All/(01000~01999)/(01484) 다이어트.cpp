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
	int G;
	cin >> G;
	int sqrtG = sqrt(G);
	vector<int> ans;
	FOR(i, 1, sqrtG) {
		if (G % i != 0) continue;
		int cur = i + G / i;
		int prev = i - G / i;
		if (cur != 0 && prev != 0 && cur % 2 == 0 && prev % 2 == 0) {
			ans.push_back(cur / 2);
		}
	}
	sort(ALL(ans));
	if (ans.empty()) {
		cout << -1;
	}
	else {
		for (int x : ans) {
			cout << x << "\n";
		}
	}

	return 0;
}