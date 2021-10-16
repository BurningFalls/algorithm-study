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

struct compare {
	bool operator() (pii a, pii b) {
		if (a.first == b.first)
			return a.second > b.second;
		return a.first < b.first;
	}
};

vector<bool> used(10001, 0);
PQ<pii, vector<pii>, compare> pq;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int P, D;
		cin >> P >> D;
		pq.push({ P, D });
	}
	int ans = 0;
	while (!pq.empty()) {
		int money = pq.top().first;
		int day = pq.top().second;
		pq.pop();
		while (day >= 1 && used[day]) {
			day--;
		}
		if (day != 0) {
			used[day] = 1;
			ans += money;
		}
	}
	cout << ans;

	return 0;
}