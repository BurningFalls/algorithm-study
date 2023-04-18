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
	string s;
	getline(cin, s);
	s += ' ';
	vector<string> v;
	string t = "";
	FOR(i, 0, LEN(s) - 1) {
		if (s[i] == ' ') {
			v.push_back(t);
			t = "";
		}
		else {
			t += s[i];
		}
	}

	int left = 0;
	int ans = 0;
	// [ = -1
	vector<int> vec;
	FOR(i, 0, LEN(v) - 1) {
		if (v[i] == "[") {
			vec.push_back(-1);
		}
		else if (v[i] == "]") {
			int sum = 8;
			while (!vec.empty() && vec.back() != -1) {
				sum += vec.back();
				vec.pop_back();
			}
			vec.pop_back();
			ans += sum;
		}
		else if (v[i][0] >= '0' && v[i][0] <= '9') {
			vec.push_back(8);
		}
		else {
			vec.push_back(LEN(v[i]) + 12);
		}
	}
	cout << ans;

	return 0;
}