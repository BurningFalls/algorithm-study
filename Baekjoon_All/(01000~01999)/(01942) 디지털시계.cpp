#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	FOR(x, 1, 3) {
		int num1, num2, num3;
		int time1, time2;
		char c;
		int cnt = 0;
		cin >> num1 >> c >> num2 >> c >> num3;
		time1 = num1 * 10000 + num2 * 100 + num3;
		cin >> num1 >> c >> num2 >> c >> num3;
		time2 = num1 * 10000 + num2 * 100 + num3;
		while (time1 != time2) {
			if (time1 % 3 == 0)
				cnt++;
			time1++;
			if (time1 % 100 == 60) {
				time1 += 40;
				if (time1 % 10000 == 6000) {
					time1 += 4000;
					if (time1 == 240000) {
						time1 = 0;
					}
				}
			}
		}
		if (time2 % 3 == 0)
			cnt++;
		cout << cnt << "\n";
	}

	return 0;
}