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
	int T;
	cin >> T;
	while (T--) {
		char a, b; int c;
		cin >> a >> b >> c;
		int tmp1 = (a - 'A' + 1) + (b - '0');
		int tmp2 = ((c - 1) / 8 + 1) + ((c - 1) % 8 + 1);
		cout << (tmp1 % 2 == tmp2 % 2 ? "YES" : "NO") << "\n";
	}

	return 0;
}