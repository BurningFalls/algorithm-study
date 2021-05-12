#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int cnt[10001];

bool cmp(pii a, pii b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int main() {
	FASTIO;
	while (true) {
		memset(cnt, 0, sizeof(cnt));
		int N, M;
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		FOR(i, 1, N) {
			FOR(j, 1, M) {
				int num;
				cin >> num;
				cnt[num]++;
			}
		}
		vector<pii> v;
		FOR(i, 1, 10000) {
			if (cnt[i] == 0) continue;
			v.push_back({ i, cnt[i] });
		}
		sort(v.begin(), v.end(), cmp);
		int first = v[0].second;
		int idx = 0;
		int len = v.size();
		while (idx < len && v[idx].second == first)
			idx++;
		int sec = v[idx].second;
		while (idx < len && v[idx].second == sec) {
			cout << v[idx].first << " ";
			idx++;
		}
		cout << "\n";
	}

	return 0;
}