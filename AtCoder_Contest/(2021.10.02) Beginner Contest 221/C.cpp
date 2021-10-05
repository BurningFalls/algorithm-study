#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	bool flag = true;
	ll maxi = 0;
	while (flag) {
		FOR(i, 1, LEN(s) / 2) {
			string s1 = s.substr(0, i);
			string s2 = s.substr(i, LEN(s) - i);
			if (s1[0] == '0' || s2[0] == '0') continue;
			maxi = max(maxi, (ll)stol(s1) * (ll)stol(s2));
		}
		flag = next_permutation(s.begin(), s.end());
	}
	cout << maxi;


	return 0;
}