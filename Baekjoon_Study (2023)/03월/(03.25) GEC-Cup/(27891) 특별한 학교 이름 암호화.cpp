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

	map<string, string> mp2;
	vector<string> v;
	for (const auto& x : mp) {
		string t = x.second;
		string s = "";
		FOR(i, 0, LEN(t) - 1) {
			if (t[i] == ' ' || t[i] == '.') {
				continue;
			}
			if (t[i] >= 'A' && t[i] <= 'Z') {
				s += t[i] - 'A' + 'a';
			}
			else {
				s += t[i];
			}
		}
		mp2[x.first] = s;
	}

	string input;
	cin >> input;
	for (const auto& x : mp2) {
		string s = x.second;
		int num = (s[0] - input[0] + 26) % 26;
		bool flag = true;
		FOR(i, 1, 9) {
			if ((s[i] - input[i] + 26) % 26 != num) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << x.first;
			break;
		}
	}

	return 0;
}