#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	string s[4];
	string T;
	FOR(i, 1, 3)
		cin >> s[i];
	cin >> T;
	FOR(i, 0, LEN(T) - 1) {
		cout << s[T[i] - '0'];
	}



	return 0;
}