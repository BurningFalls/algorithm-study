#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

map<int, int> mp;
map<int, int>::iterator it_m;
set<int> s;
set<int>::iterator it_s;

int main() {
	FASTIO;
	int n, q;
	cin >> n >> q;
	int num;
	FOR(i, 1, n) {
		cin >> num;
		s.insert(num);
	}
	it_s = s.begin();
	int prev = *it_s;
	it_s++;
	while (it_s != s.end()) {
		int temp = *it_s - prev;
		prev = *it_s;
		it_s++;
		if (mp.count(temp))
			mp[temp] += 1;
		else
			mp.insert({ temp, 1 });
	}
	it_m = mp.begin();
	int ans = 0;
	int left = n - 2;
	while (it_m != mp.end()) {
		int temp = it_m->second;
		if (left <= temp) {
			ans += it_m->first * left;
			break;
		}
		else {
			ans += it_m->first * temp;
			left -= temp;
			it_m++;
		}
	}
	cout << ans << "\n";

	FOR(i, 1, q) {
		int t, x;
		cin >> t >> x;
		if (t == 0) {
			it_s = s.find(x);
			int le, mi, ri;
			mi = *it_s;
			if (s.size() == 1) {
				mp.clear();
			}
			else if (it_s == s.begin()) {
				it_s++;
				ri = *it_s;
				int X = ri - mi;
				mp[X] -= 1;
				if (mp[X] == 0)
					mp.erase(X);
			}
			else if (it_s == --s.end()) {
				it_s--;
				le = *it_s;
				int X = mi - le;
				mp[X] -= 1;
				if (mp[X] == 0)
					mp.erase(X);
			}
			else {
				it_s--;
				le = *it_s;
				it_s++;
				it_s++;
				ri = *it_s;
				int X = ri - mi;
				mp[X] -= 1;
				if (mp[X] == 0)
					mp.erase(X);
				X = mi - le;
				mp[X] -= 1;
				if (mp[X] == 0)
					mp.erase(X);
				X = ri - le;
				if (mp.count(X))
					mp[X] += 1;
				else
					mp.insert({ X, 1 });
			}
			s.erase(s.find(x));
			n -= 1;
		}
		else if (t == 1) {
			s.insert(x);
			it_s = s.find(x);
			int le, mi, ri;
			mi = *it_s;
			if (s.size() == 1) {
				;
			}
			else if (it_s == s.begin()) {
				it_s++;
				ri = *it_s;
				int X = ri - mi;
				if (mp.count(X))
					mp[X] += 1;
				else
					mp.insert({ X, 1 });
			}
			else if (it_s == --s.end()) {
				it_s--;
				le = *it_s;
				int X = mi - le;
				if (mp.count(X))
					mp[X] += 1;
				else
					mp.insert({ X, 1 });
			}
			else {
				it_s--;
				le = *it_s;
				it_s++;
				it_s++;
				ri = *it_s;
				int X = ri - mi;
				if (mp.count(X))
					mp[X] += 1;
				else
					mp.insert({ X, 1 });
				X = mi - le;
				if (mp.count(X))
					mp[X] += 1;
				else
					mp.insert({ X, 1 });
				X = ri - le;
				mp[X] -= 1;
				if (mp[X] == 0)
					mp.erase(X);
			}
			n += 1;
		}
		it_m = mp.begin();
		ans = 0;
		left = n - 2;
		while (it_m != mp.end()) {
			int temp = it_m->second;
			if (left <= temp) {
				ans += it_m->first * left;
				break;
			}
			else {
				ans += it_m->first * temp;
				left -= temp;
				it_m++;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}