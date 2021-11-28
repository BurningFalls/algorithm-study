#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

char arr[12] = { 'A', 'B', 'E', 'K',
'M', 'H', 'O', 'P',
'C', 'T', 'Y', 'X' };
string arr2[12] = { "a", "v", "ye", "k",
"m", "n", "o", "r",
"s", "t", "u", "h" };

int main() {
	FASTIO;
	string s;
	cin >> s;
	FOR(i, 0, LEN(s) - 1) {
		FOR(j, 0, 11) {
			if (s[i] == arr[j]) {
				cout << arr2[j];
				break;
			}
		}
	}


	return 0;
}