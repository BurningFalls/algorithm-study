#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int K, C;
	cin >> K >> C;
	FOR(i, 1, C) {
		int a, b;
		cin >> a >> b;
		int remain = K - max(a, b);
		int diff = abs(a - b);
		if (a == b)
			cout << 1;
		else if (a > b) {
			if (diff - remain <= 2)
				cout << 1;
			else
				cout << 0;
		}
		else if (a < b) {
			if (diff - remain <= 1)
				cout << 1;
			else
				cout << 0;
		}
		cout << "\n";
	}

	return 0;
}