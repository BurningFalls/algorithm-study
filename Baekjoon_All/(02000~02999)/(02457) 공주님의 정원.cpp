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

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<pii> v;
	FOR(i, 0, N - 1) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int start = 100 * a + b;
		int end = 100 * c + d;
		if (start >= end) continue;
		v.push_back({ start, end });
	}
	sort(ALL(v));

	int right = 301;
	int idx = 0;
	int cnt = 0;
	while (idx < N && right <= 1130) {
		int nright = 0;
		while (idx < N && v[idx].first <= right) {
			nright = max(nright, v[idx].second);
			idx++;
		}
		if (nright == 0) break;
		right = nright;
		cnt++;
	}
	cout << (right > 1130 ? cnt : 0);

	return 0;
}