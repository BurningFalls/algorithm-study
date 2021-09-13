#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

vector<pii> v;

bool cmp(pii a, pii b) {
	if (a.second == b.second)
		return a.first > b.first;
	return a.second < b.second;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		v.clear();
		int N, M;
		cin >> N >> M;
		FOR(i, 1, N * M) {
			int num;
			cin >> num;
			v.push_back({ i, num });
		}
		sort(v.begin(), v.end(), cmp);
		int ans = 0;
		FOR(i, 0, N* M - 2) {
			int cnt = 0;
			FOR(j, i + 1, N * M - 1) {
				if (v[i].first < v[j].first)
					cnt++;
			}
			ans += cnt;
		}
		cout << ans << "\n";
	}

	return 0;
}