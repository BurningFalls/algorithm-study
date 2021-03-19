#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		int n = 1;
		int A = 1, B = 1;
		while (true) {
			if (((n - 1) * n) / 2 + 1 <= a && a <= (n * (n + 1)) / 2)
				A = n;
			if (((n - 1) * n) / 2 + 1 <= b && b <= (n * (n + 1)) / 2) {
				B = n;
				break;
			}
			n++;
		}
		int ax, ay, bx, by;
		int tmp = (A - 1) * A / 2 + 1;
		ax = 1 + a - tmp;
		ay = A - (a - tmp);
		tmp = (B - 1) * B / 2 + 1;
		bx = 1 + b - tmp;
		by = B - (b - tmp);
		int sumx = ax + bx;
		int sumy = ay + by;
		tmp = (sumx + sumy) - 1;
		int start = (tmp - 1) * tmp / 2 + 1;
		cout << (sumx - 1) + start << "\n";
	}



	return 0;
}