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
	int a = 0, b = 0;
	cin >> s;
	for (int i = 0; i < LEN(s); i += 2) {
		if (s[i] == 'A') {
			a += s[i + 1] - '0';
		}
		else if (s[i] == 'B') {
			b += s[i + 1] - '0';
		}
	}
	cout << (a > b ? 'A' : 'B');

	return 0;
}