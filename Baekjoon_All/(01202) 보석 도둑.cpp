#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

vector<pair<int, int>> v;
int C[300001];
bool visited[300001] = { 0, };
vector<int> c_v;

int main() {
	FASTIO;
	int N, K;
	ll ans = 0;
	priority_queue<int> pq;
	cin >> N >> K;
	FOR(i, 1, N) {
		int M, V;
		cin >> M >> V;
		v.push_back({ M, V });
	}
	FOR(i, 1, K) {
		int C;
		cin >> C;
		c_v.push_back(C);
	}
	sort(v.begin(), v.end());
	sort(c_v.begin(), c_v.end());
	int idx = 0;
	FOR(i, 0, K - 1) {
		while (idx < N) {
			if (v[idx].first <= c_v[i])
				pq.push(v[idx].second);
			else
				break;
			idx++;
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;

	return 0;
}