#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int d, n, s, p;
		cin >> d >> n >> s >> p;
		int temp1 = d + p * n;
		int temp2 = s * n;
		if (temp1 < temp2)
			cout << "parallelize";
		else if (temp1 > temp2)
			cout << "does not parallelize";
		else if (temp1 == temp2)
			cout << "does not matter";
		cout << "\n";
	}

	return 0;
}