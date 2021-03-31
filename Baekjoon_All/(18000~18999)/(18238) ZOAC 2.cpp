#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string s;
	cin >> s;
	int prev = 0;
	int len = s.size();
	int ans = 0;
	FOR(i, 0, len - 1) {
		int cur = s[i] - 'A';
		int a = (prev - cur + 26) % 26;
		int b = (cur - prev + 26) % 26;
		ans += min(a, b);
		prev = cur;
	}
	cout << ans;


	return 0;
}