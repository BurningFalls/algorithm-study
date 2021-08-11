#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool is_Prime(int x) {
	int tmp = sqrt(x);
	FOR(i, 2, tmp) {
		if (x % i == 0)
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	int a, b;
	cin >> a >> b;
	if (is_Prime(a) && is_Prime(a + b * 1000000))
		cout << "Yes";
	else
		cout << "No";


	return 0;
}