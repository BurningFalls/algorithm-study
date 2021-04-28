#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

map<string, int> mp;

int main() {
	FASTIO;
	int N;
	int ans = 0;
	cin >> N;
	FOR(i, 1, N) {
		string str;
		cin >> str;
		if (mp.count(str)) {
			if ((i - 1) - mp[str] < mp[str]) {
				ans++;
			}
			mp[str] += 1;
		}
		else {
			mp.insert({ str, 1 });
		}
	}
	cout << ans;


	return 0;
}