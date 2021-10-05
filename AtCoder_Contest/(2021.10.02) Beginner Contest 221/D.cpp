#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int ans[200001] = { 0, };
map<int, pii> mp;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		if (!mp.count(a))
			mp[a] = { 0, 0 };
		if (!mp.count(a + b - 1))
			mp[a + b - 1] = { 0, 0 };
		mp[a].first += 1;
		mp[a + b - 1].second += 1;
	}
	int cnt = 0;
	int prev = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		int num = (*it).first;
		int s = (*it).second.first;
		int e = (*it).second.second;
		ans[cnt] += (num - prev - 1);
		cnt += s;
		ans[cnt] += 1;
		cnt -= e;
		prev = num;
	}
	FOR(i, 1, N)
		cout << ans[i] << " ";

	return 0;
}