#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	string s;
	cin >> s;
	if (LEN(s) < 5) {
		cout << "not cute";
	}
	else {
		string sub_str = s.substr(LEN(s) - 5, 5);
		if (sub_str == "driip") {
			cout << "cute";
		}
		else {
			cout << "not cute";
		}
	}


	return 0;
}