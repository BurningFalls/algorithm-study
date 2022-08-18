#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

map<int, map<int, int>> mp;
map<int, int> topping;
int one_cnt = 0;
ll sum = 0;

int Gcd(int a, int b) {
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}

void doOne(int tmp, int t) {
	if (mp[tmp].count(t)) {
		mp[tmp][t]++;
	}
	else {
		sum += t;
		if (LEN(mp[tmp]) == 0) {
			one_cnt++;
		}
		else if (LEN(mp[tmp]) == 1) {
			one_cnt--;
		}
		mp[tmp].insert({ t, 1 });
	}
}

void doTwo(int tmp, int topp) {
	if (mp[tmp][topp] == 1) {
		sum -= topp;
		if (LEN(mp[tmp]) == 1) {
			one_cnt--;
			mp.erase(tmp);
		}
		else if (LEN(mp[tmp]) == 2) {
			one_cnt++;
			mp[tmp].erase(topp);
		}
		else {
			mp[tmp].erase(topp);
		}
	}
	else {
		mp[tmp][topp]--;
	}
}

int main() {
	FASTIO;
	int N, L, Q;
	cin >> N >> L >> Q;
	int gcd = Gcd(N, L);
	
	FOR(q, 1, Q) {
		int kind, x, t;
		cin >> kind >> x;
		if (kind == 1) {
			cin >> t;
			if (topping.count(x) && topping[x] != 0) {
				doTwo((x - 1) % gcd, topping[x]);
			}
			doOne((x - 1) % gcd, t);
			topping[x] = t;
		}
		else if (kind == 2) {
			doTwo((x - 1) % gcd, topping[x]);
			topping[x] = 0;
		}
		if (LEN(mp) == one_cnt) {
			cout << "YES " << sum;
		}
		else {
			cout << "NO";
		}
		cout << "\n";
	}

	return 0;
}