#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<ll, int>
#define LEN(s) int(s.size())

map<int, int> mp;
map<int, int> mp2;
vector<pii> v;

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		mp.clear();
		mp2.clear();
		v.clear();
		int N;
		cin >> N;
		FOR(i, 1, N) {
			int num;
			cin >> num;
			mp[num] += 1;
		}
		for (auto it = mp.begin(); it != mp.end(); it++)
			mp2[(*it).second]++;
		for (auto it = mp2.begin(); it != mp2.end(); it++)
			v.push_back(*it);
		ll left = v[0].first;
		ll right = v[LEN(v) - 1].first;
		int min_sum = -1;
		FOR(i, left, right) {
			ll sum = 0;
			FOR(j, 0, LEN(v) - 1) {
				if (v[j].first >= i)
					sum += (v[j].first - i) * v[j].second;
				else
					sum += v[j].first * v[j].second;
			}
			if (min_sum == -1 || min_sum > sum)
				min_sum = sum;
		}
		cout << min_sum << "\n";
	}

	return 0;
}