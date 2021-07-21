#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

map<string, priority_queue<int>> mp;

int main() {
	FASTIO;
	int Q;
	cin >> Q;
	ll sum = 0;
	FOR(q, 1, Q) {
		int kind;
		string name;
		int k, b;
		cin >> kind;
		cin >> name;
		if (kind == 1) {
			cin >> k;
			FOR(i, 1, k) {
				int num;
				cin >> num;
				mp[name].push(num);
			}
		}
		else if (kind == 2) {
			cin >> b;
			int len = mp[name].size();
			FOR(i, 1, min(len, b)) {
				sum += mp[name].top();
				mp[name].pop();
			}
		}
	}
	cout << sum;


	return 0;
}