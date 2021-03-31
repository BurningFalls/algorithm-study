#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int hour, minute;
	cin >> hour >> minute;
	bool flag = false;
	for (int x = 0; x < 720; x += 2) {
		int a = (6 * x) % 360;
		int b = (x / 2) % 360;
		if (a == minute && b == hour) {
			flag = true;
			break;
		}
	}
	if (flag)
		cout << "O";
	else
		cout << "X";


	return 0;
}