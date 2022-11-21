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
	cin >> s;
	ll sum = 0;
	vector<int> v;
	v.push_back(-1);
	FOR(i, 0, LEN(s) - 1) {
		if (s[i] == '(') {
			v.push_back(v.back() + 1);
		}
		else if (s[i] == ')') {
			if (i != 0 && s[i - 1] == '(') {
				sum += v.back();
			}
			v.pop_back();
		}
	}
	cout << sum;

	return 0;
}