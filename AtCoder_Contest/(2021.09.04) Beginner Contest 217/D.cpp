#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

map<int, int> mp;

int main() {
	FASTIO;
	int L, Q;
	cin >> L >> Q;
	mp.insert({ 0, L });
	FOR(q, 1, Q) {
		int c, x;
		cin >> c >> x;
		if (c == 1) {
			auto it = mp.upper_bound(x);
			it--;
			int tmp = (*it).second;
			(*it).second = x;
			mp.insert({ x, tmp });
		}
		else if (c == 2) {
			auto it = mp.upper_bound(x);
			it--;
			cout << (*it).second - (*it).first << "\n";
		}
	}



	return 0;
}