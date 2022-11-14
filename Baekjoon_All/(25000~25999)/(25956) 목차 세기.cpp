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
	int N;
	cin >> N;
	vector<int> L(N + 1);
	vector<int> cnt(N + 1, 0);
	FOR(i, 1, N) {
		cin >> L[i];
	}
	L[0] = 0;
	vector<pii> v;
	bool flag = true;
	v.push_back({ 0, 0 });
	FOR(i, 1, N) {
		while (v.back().first >= L[i]) {
			v.pop_back();
		}
		if (v.back().first + 1 != L[i]) {
			flag = false;
			break;
		}
		cnt[v.back().second]++;
		v.push_back({ L[i], i });
	}
	if (!flag) {
		cout << -1;
	}
	else {
		FOR(i, 1, N) {
			cout << cnt[i] << "\n";
		}
	}

	return 0;
}