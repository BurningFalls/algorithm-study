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
	int ecnt = 0;
	FOR(i, 0, LEN(s) - 1) {
		ecnt += (s[i] == 'e');
	}
	cout << 'h';
	FOR(i, 1, ecnt * 2) {
		cout << 'e';
	}
	cout << 'y';

	return 0;
}