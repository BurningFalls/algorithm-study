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
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

int main() {
	FASTIO;
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> X(N + 1);
	vector<bool> check(N + 1, 0);
	vector<pii> v;
	FOR(i, 1, N) {
		cin >> X[i];
	}
	FOR(k, 1, K) {
		int n;
		cin >> n;
		check[n] = 1;
	}
	int sum = 0;
	ROF(i, N, 1) {
		sum += X[i];
		if (check[i]) {
			v.push_back({ sum, i });
			sum = 0;
		}
	}
	sort(ALL(v), compare);

	vector<int> ans;
	FOR(i, 0, min(M, K) - 1) {
		ans.push_back(v[i].second);
	}
	sort(ALL(ans));
	for (int x : ans) {
		cout << x << "\n";
	}

	return 0;
}