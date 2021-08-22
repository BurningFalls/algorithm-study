#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N, K;
	string s;
	cin >> N;
	cin >> s;
	cin >> K;
	bool flag = true;
	FOR(i, max(0, N - K), N - 1) {
		if (s[i] == '1')
			flag = false;
	}
	cout << (flag ? "YES" : "NO");

	return 0;
}