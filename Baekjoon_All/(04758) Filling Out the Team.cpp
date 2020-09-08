#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	double a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		bool flag = false;
		if (a <= 4.5 && b >= 150 && c >= 200) {
			cout << "Wide Receiver ";
			flag = true;
		}
		if (a <= 6.0 && b >= 300 && c >= 500) {
			cout << "Lineman ";
			flag = true;
		}
		if (a <= 5.0 && b >= 200 && c >= 300) {
			cout << "Quarterback ";
			flag = true;
		}
		if (!flag)
			cout << "No positions";
		cout << "\n";
	}

	return 0;
}