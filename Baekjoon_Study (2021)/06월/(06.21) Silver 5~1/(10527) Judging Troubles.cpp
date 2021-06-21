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
	cin >> N;
	FOR(i, 1, N) {
		string s;
		cin >> s;
		mp[s] += 1;
	}
	int cnt = 0;
	FOR(i, 1, N) {
		string s;
		cin >> s;
		if (mp.count(s) && mp[s] != 0) {
			cnt++;
			mp[s] -= 1;
		}
	}
	cout << cnt;


	return 0;
}