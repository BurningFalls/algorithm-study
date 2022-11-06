#include <bits/stdc++.h>
using namespace std;

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
	int N;
	string s;
	cin >> N;
	cin >> s;
	vector<int> v;
	int maxi = -1;
	FOR(i, 0, N - 1) {
		if (s[i] == '(') {
			if (v.empty() || v.back() == 1) {
				v.push_back(1);
			}
			else if (v.back() == 0) {
				v.pop_back();
				maxi = max(maxi, LEN(v) + 1);
			}
		}
		else if (s[i] == ')') {
			if (v.empty() || v.back() == 0) {
				v.push_back(0);
			}
			else if (v.back() == 1) {
				v.pop_back();
				maxi = max(maxi, LEN(v) + 1);
			}
		}
	}
	if (!v.empty()) {
		maxi = -1;
	}
	cout << maxi;

	return 0;
}