#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool Check(int x) {
	int tmp = sqrt(x);
	return (tmp * tmp == x);
}

bool two_Check(int x) {
	if (x <= 1)
		return false;
	while (x != 1) {
		if (x % 2 == 1)
			return false;
		x /= 2;
	}
	return true;
}

int main() {
	FASTIO;
	int A, B, C;
	cin >> A >> B >> C;
	int tmp = B * B - 4 * A * C;
	if (tmp <= 0 || !Check(tmp))
		cout << "둘다틀렸근";
	else {
		int x = -B - sqrt(tmp);
		int y = -B + sqrt(tmp);
		int down = 2 * A;
		if ((x % down == 0) && (y % down == 0)) {
			x /= down; y /= down;
			if (two_Check(x) && two_Check(y))
				cout << "이수근";
			else
				cout << "정수근";
		}
		else
			cout << "둘다틀렸근";
	}


	return 0;
}