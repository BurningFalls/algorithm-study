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

bool compare(pair<string, string> a, pair<string, string> b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<pair<string, string>> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i].first >> v[i].second;
	}
	sort(ALL(v), compare);
	FOR(i, 0, N - 1) {
		cout << v[i].first << " " << v[i].second << "\n";
	}

	return 0;
}