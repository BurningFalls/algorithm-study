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
	int X;
	cin >> X;
	if (X >= 0 && X < 40)
		cout << 40 - X;
	else if (X >= 40 && X < 70)
		cout << 70 - X;
	else if (X >= 70 && X < 90)
		cout << 90 - X;
	else
		cout << "expert";


	return 0;
}