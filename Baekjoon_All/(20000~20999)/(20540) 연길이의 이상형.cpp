#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	char arr[8] = { 'E', 'S', 'T', 'J', 'I', 'N', 'F', 'P' };
	char ch_arr[8] = { 'I', 'N', 'F', 'P', 'E', 'S', 'T', 'J' };
	string s;
	cin >> s;
	FOR(i, 0, 3) {
		FOR(j, 0, 7) {
			if (s[i] == arr[j])
				cout << ch_arr[j];
		}
	}


	return 0;
}