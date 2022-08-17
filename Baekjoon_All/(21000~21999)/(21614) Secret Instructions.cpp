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
	string prev = "prev";
	while (true) {
		cin >> s;
		if (s == "99999") break;
		int a = s[0] - '0';
		int b = s[1] - '0';
		int c = stoi(s.substr(2, 3));
		if ((a + b) % 2 == 1) {
			prev = "left";
		}
		else if ((a + b) != 0 && (a + b) % 2 == 0) {
			prev = "right";
		}
		cout << prev << " " << c << "\n";
	}

	return 0;
}