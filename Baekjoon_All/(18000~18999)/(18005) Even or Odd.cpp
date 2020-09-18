#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int n;
	cin >> n;
	int temp = (n - 1) % 4 + 1;
	if (temp == 1 || temp == 3)
		cout << 0;
	else if (temp == 2)
		cout << 1;
	else if (temp == 4)
		cout << 2;

	return 0;
}