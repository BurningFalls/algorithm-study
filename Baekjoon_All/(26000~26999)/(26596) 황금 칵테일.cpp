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

int main() {
	FASTIO;
	int M;
	cin >> M;
	map<string, double> mp;
	FOR(i, 1, M) {
		string s;
		double x;
		cin >> s >> x;
		mp[s] += x;
	}

	bool flag = false;
	for (const auto& n1 : mp) {
		for (const auto& n2 : mp) {
			if (n1.first == n2.first) continue;
			if (floor(n1.second * 1.618) == int(n2.second)) {
				flag = true;
			}
		}
	}

	cout << (flag ? "Delicious!" : "Not Delicious...");

	return 0;
}