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

struct compare1 {
	bool operator()(pii a, pii b) {
		if (a.first == b.first)
			return a.second > b.second;
		return a.first > b.first;
	}
};

struct compare2 {
	bool operator()(pair<pii, int> a, pair<pii, int> b) {
		if (a.first.first == b.first.first)
			return a.first.second < b.first.second;
		return a.first.first > b.first.first;
	}
};


PQ<pii, vector<pii>, compare1> In;
PQ<pair<pii, int>, vector<pair<pii, int>>, compare2> Out;

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, K) {
		In.push({ 0, i });
	}
	FOR(i, 1, N) {
		int id, w;
		cin >> id >> w;
		int block_time = In.top().first;
		int block_idx = In.top().second;
		In.pop();
		In.push({ block_time + w, block_idx });
		Out.push({ {block_time + w, block_idx}, id });
	}
	ll ans = 0;
	int num = 1;
	while (!Out.empty()) {
		ll idx = Out.top().second;
		Out.pop();
		ans += num * idx;
		num++;
	}
	cout << ans;


	return 0;
}