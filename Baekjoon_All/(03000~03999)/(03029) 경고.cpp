#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	string a, b;
	int temp1, temp2;
	int ans;
	cin >> a >> b;
	temp1 = 3600 * ((a[0] - '0') * 10 + (a[1] - '0')) + 60 * ((a[3] - '0') * 10 + (a[4] - '0')) + (a[6] - '0') * 10 + (a[7] - '0');
	temp2 = 3600 * ((b[0] - '0') * 10 + (b[1] - '0')) + 60 * ((b[3] - '0') * 10 + (b[4] - '0')) + (b[6] - '0') * 10 + (b[7] - '0');
	if (temp1 == temp2)
		cout << "24:00:00";
	else {
		if (temp1 > temp2)
			ans = 24 * 3600 + temp2 - temp1;
		else if (temp1 < temp2)
			ans = temp2 - temp1;
		int x, y, z;
		x = ans / 3600;
		ans -= x * 3600;
		y = ans / 60;
		ans -= y * 60;
		z = ans;
		if (x < 10)
			cout << "0";
		cout << x << ":";
		if (y < 10)
			cout << "0";
		cout << y << ":";
		if (z < 10)
			cout << "0";
		cout << z;
	}

	return 0;
}