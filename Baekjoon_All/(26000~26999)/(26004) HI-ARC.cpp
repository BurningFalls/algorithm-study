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
	int N;
	cin >> N;
	string s;
	cin >> s;
	vector<int> cnt(5, 0);
	FOR(i, 0, N - 1) {
		if (s[i] == 'H') cnt[0]++;
		else if (s[i] == 'I') cnt[1]++;
		else if (s[i] == 'A') cnt[2]++;
		else if (s[i] == 'R') cnt[3]++;
		else if (s[i] == 'C') cnt[4]++;
	}
	cout << min({ cnt[0], cnt[1], cnt[2], cnt[3], cnt[4] });

	return 0;
}