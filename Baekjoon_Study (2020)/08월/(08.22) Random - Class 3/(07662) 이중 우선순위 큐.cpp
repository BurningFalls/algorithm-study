#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		set<pair<ll, int>> s;
		set<pair<ll, int>>::iterator it;
		int K;
		cin >> K;
		FOR(i, 1, K) {
			char x;
			ll n;
			cin >> x >> n;
			if (x == 'D') {
				if (s.empty()) continue;
				if (n == 1) {
					it = s.end();
					it--;
					s.erase(it);
				}
				else if (n == -1) {
					it = s.begin();
					s.erase(it);
				}
			}
			else if (x == 'I') {
				s.insert(make_pair(n, i));
			}
		}
		if (s.empty())
			cout << "EMPTY";
		else {
			it = s.end();
			it--;
			cout << (*it).first << " ";
			it = s.begin();
			cout << (*it).first;
		}
		cout << "\n";
	}

	return 0;
}