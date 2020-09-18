#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int a;
	int arr[41];
	while (true) {
		int trees = 1;
		cin >> a;
		if (a == 0)
			break;
		FOR(i, 1, a) {
			int x, y;
			cin >> x >> y;
			trees *= x;
			trees -= y;
		}
		cout << trees << "\n";
	}

	return 0;
}