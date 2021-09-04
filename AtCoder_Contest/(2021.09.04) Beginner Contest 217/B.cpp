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
	string arr[4] = { "ABC", "ARC", "AGC", "AHC" };
	int idx = 0;
	bool flag[4] = { 0, };
	FOR(i, 0, 2) {
		string s;
		cin >> s;
		FOR(j, 0, 3) {
			if (arr[j] == s)
				flag[j] = 1;
		}
	}
	FOR(i, 0, 3) {
		if (flag[i] == 0)
			idx = i;
	}
	cout << arr[idx];


	return 0;
}