#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MAX(a,b) a = max(a, b)

int main() {
	FASTIO;
	int N, M, K;
	string s;
	map<string, int> mp;
	map<string, int>::iterator iter;
	int maximum = 0;
	int ans;
	cin >> N >> M;
	FOR(i, 0, N - 1) {
		cin >> s;
		if (mp.count(s))
			mp[s] += 1;
		else
			mp.insert(make_pair(s, 1));
	}
	cin >> K;

	for (iter = mp.begin(); iter != mp.end(); iter++) {
		string temp = iter->first;
		int cnt = 0;
		FOR(i, 0, M - 1) {
			if (temp[i] == '0')
				cnt++;
		}
		if (cnt <= K && (K - cnt) % 2 == 0) {
			MAX(maximum, iter->second);
		}
	}
	cout << maximum;

	return 0;
}