#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int N, M;
	string s1, s2;
	map<string, string> mp;
	cin >> N >> M;
	FOR(i, 1, N) {
		cin >> s1 >> s2;
		mp.insert(make_pair(s1, s2));
	}
	FOR(i, 1, M) {
		cin >> s1;
		cout << mp[s1] << "\n";
	}

	return 0;
}