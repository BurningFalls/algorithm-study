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
		string a, b, ta, tb;
		cin >> a >> b;
		ta = a; tb = b;
		sort(ALL(ta));
		sort(ALL(tb));
		cout << a << " & " << b << " are ";
		if (ta != tb) cout << "NOT ";
		cout << "anagrams.\n";
	}

	return 0;
}