#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<pii> v;
priority_queue<int> pq;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int s, t;
		cin >> s >> t;
		v.push_back({ s, t });
	}
	sort(v.begin(), v.end());
	FOR(i, 0, N - 1) {
		if (pq.empty()) {
			pq.push(-v[i].second);
			continue;
		}
		if (-pq.top() <= v[i].first)
			pq.pop();
		pq.push(-v[i].second);
	}
	int len = pq.size();
	cout << len;

	return 0;
}