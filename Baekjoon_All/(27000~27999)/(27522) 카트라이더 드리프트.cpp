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
	vector<pair<string, char>> v(8);
	FOR(i, 0, 7) {
		cin >> v[i].first >> v[i].second;
	}
	sort(ALL(v));

	vector<int> score = { 10, 8, 6, 5, 4, 3, 2, 1 };
	int r = 0, b = 0;
	FOR(i, 0, 7) {
		r += (v[i].second == 'R') * score[i];
		b += (v[i].second == 'B') * score[i];
	}
	cout << (r > b ? "Red" : "Blue");

	return 0;
}