#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int X, Y;
	char c;
	cin >> X >> c >> Y;
	cout << X;
	if (Y >= 0 && Y <= 2)
		cout << '-';
	else if (Y >= 7 && Y <= 9)
		cout << '+';


	return 0;
}