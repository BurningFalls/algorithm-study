#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		int temp = abs(a - b);
		if (temp % 10 == 0)
			cout << temp / 10;
		else
			cout << temp / 10 + 1;
		cout << "\n";
	}

	return 0;
}