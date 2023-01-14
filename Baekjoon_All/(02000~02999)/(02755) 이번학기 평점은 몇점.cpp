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
	map<string, double> mp;
	mp["A+"] = 4.3, mp["A0"] = 4.0, mp["A-"] = 3.7;
	mp["B+"] = 3.3, mp["B0"] = 3.0, mp["B-"] = 2.7;
	mp["C+"] = 2.3, mp["C0"] = 2.0, mp["C-"] = 1.7;
	mp["D+"] = 1.3, mp["D0"] = 1.0, mp["D-"] = 0.7;
	mp["F"] = 0.0;
	int N;
	cin >> N;
	double sum = 0;
	double ans = 0;
	FOR(i, 1, N) {
		string s; int x; string y;
		cin >> s >> x >> y;
		sum += x;
		ans += x * mp[y];
	}
	cout << fixed << setprecision(2);
	float result = ans / sum;
	cout << result;

	return 0;
}