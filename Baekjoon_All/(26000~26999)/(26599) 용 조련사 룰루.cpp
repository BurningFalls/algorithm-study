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

bool compare(pii a, pii b) {
	return a.second > b.second;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<pii> P(N);
	FOR(i, 0, N - 1) {
		P[i].first = i + 1;
		cin >> P[i].second;
	}
	sort(ALL(P), compare);
	int idx = N - 1;
	FOR(i, 0, N - 2) {
		if (P[i].second - P[i + 1].second > M) {
			idx = min(idx, i);
		}
	}
	
	bool flag = false;
	if (N <= 3 && idx == N - 1) {
		flag = true;
	}
	else if (N >= 4 && idx >= 3) {
		flag = true;
	}

	if (!flag) {
		cout << "NO";
	}
	else if (flag) {
		cout << "YES\n";
		FOR(i, 0, min(N - 1, 1)) {
			cout << P[i].first << " ";
		}
		FOR(i, idx + 1, N - 1) {
			cout << P[i].first << " ";
		}
		FOR(i, 2, idx) {
			cout << P[i].first << " ";
		}
	}

	return 0;
}