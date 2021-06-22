#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int idx = 1;
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		cout << "Hole #" << idx << "\n";
		if (b == 1)
			cout << "Hole-in-one";
		else if (a - b >= 3)
			cout << "Double eagle";
		else if (a - b == 2)
			cout << "Eagle";
		else if (a - b == 1)
			cout << "Birdie";
		else if (a - b == 0)
			cout << "Par";
		else if (a - b == -1)
			cout << "Bogey";
		else if (a - b <= -2)
			cout << "Double Bogey";
		cout << ".\n\n";
		idx++;
	}


	return 0;
}