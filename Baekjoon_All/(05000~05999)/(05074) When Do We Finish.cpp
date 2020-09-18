#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int a, b, c, d;
	char x;
	while (true) {
		cin >> a >> x >> b >> c >> x >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0)
			break;
		int temp = 60 * (a + c) + b + d;
		int hour = temp / 60;
		int minute = temp - hour * 60;
		int day = hour / 24;
		hour -= day * 24;
		if (hour < 10)
			cout << "0";
		cout << hour << ":";
		if (minute < 10)
			cout << "0";
		cout << minute;
		if (day != 0)
			cout << " +" << day;
		cout << "\n";
	}

	return 0;
}