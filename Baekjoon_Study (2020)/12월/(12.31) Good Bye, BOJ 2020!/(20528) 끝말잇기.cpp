#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	string s[101];
	char x;
	cin >> N;
	FOR(i, 1, N) {
		cin >> s[i];
	}
	x = s[1][0];
	bool flag = true;
	FOR(i, 2, N) {
		if (s[i][0] != x) {
			flag = false;
			break;
		}
	}
	cout << flag;

	return 0;
}