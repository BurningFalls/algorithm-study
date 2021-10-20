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

struct NODE {
	int month;
	int day;
};

bool operator<(NODE a, NODE b) {
	if (a.month == b.month)
		return a.day < b.day;
	return a.month < b.month;
}

bool operator==(NODE a, NODE b) {
	return a.month == b.month && a.day == b.day;
}

bool compare(pair<NODE, NODE> a, pair<NODE, NODE> b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<pair<NODE, NODE>> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i].first.month >> v[i].first.day;
		cin >> v[i].second.month >> v[i].second.day;
	}
	sort(ALL(v), compare);
	NODE end = { 3, 1 };
	NODE final = { 11, 31 };
	int idx = 0;
	int ans = 0;
	if (end < v[0].first) {
		cout << 0;
		return 0;
	}
	while (idx <= N - 1 && end < final) {
		NODE max_end = { 0, 0 };
		while (idx <= N - 1 && (v[idx].first < end || v[idx].first == end)) {
			if (max_end < v[idx].second) {
				max_end = v[idx].second;
			}
			idx++;
		}
		ans++;
		end = max_end;
	}
	cout << (end < final ? 0 : ans);

	return 0;
}