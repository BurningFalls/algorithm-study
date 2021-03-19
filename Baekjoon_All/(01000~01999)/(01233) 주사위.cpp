#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

map<int, int> mp;

int main() {
	FASTIO;
	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	FOR(i, 1, s1) {
		FOR(j, 1, s2) {
			FOR(k, 1, s3) {
				int sum = i + j + k;
				if (mp.count(sum))
					mp[sum] += 1;
				else
					mp[sum] = 1;
			}
		}
	}
	int maximum = 0;
	int ans = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		int tmp = (*it).second;
		if (maximum < tmp) {
			maximum = tmp;
			ans = (*it).first;
		}
	}
	cout << ans;

	return 0;
}