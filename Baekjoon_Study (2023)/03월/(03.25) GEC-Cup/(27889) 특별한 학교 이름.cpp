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
	map<string, string> mp;
	mp["NLCS"] = "North London Collegiate School";
	mp["BHA"] = "Branksome Hall Asia";
	mp["KIS"] = "Korea International School";
	mp["SJA"] = "St. Johnsbury Academy";

	string s;
	cin >> s;
	cout << mp[s];

	return 0;
}