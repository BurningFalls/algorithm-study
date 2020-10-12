#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int n;
	int num;
	cin >> n;
	FOR(i, 1, n) {
		cin >> num;
		if (num % 2 == 0)
			cout << num << " is even\n";
		else
			cout << num << " is odd\n";
	}

	return 0;
}